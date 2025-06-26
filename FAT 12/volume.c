#include "file_reader.h"
#include "tested_declarations.h"
#include "rdebug.h"
#include "errno.h"
#include "tested_declarations.h"
#include "rdebug.h"

#define VOLUME_PARAMETERS 11 //bytes per sector oraz ssector per cluster
#define BOOT_SIGNATURE1 0x55
#define BOOT_SIGNATURE2 0xAA
#define SIGNATURE1_POSITION BYTES_PER_SECTOR-2
#define SIGNATURE2_POSITION BYTES_PER_SECTOR-1

void calculate_fat_sectors(struct volume_t* volume, uint32_t first_sector)
{
    volume->calculated.fat_start_sector = first_sector + volume->layout.reserved_sectors_count;
    volume->calculated.root_dir_start_sector = volume->calculated.fat_start_sector + volume->layout.num_fats * volume->layout.fat_size_sectors;
    volume->calculated.root_dir_sectors = (volume->layout.max_root_dir_entries * 32) / volume->layout.bytes_per_sector;
    volume->calculated.data_start_sector = volume->calculated.root_dir_start_sector + volume->calculated.root_dir_sectors;
    volume->calculated.bytes_per_cluster = volume->layout.bytes_per_sector * volume->layout.sectors_per_cluster;
}    

int copy_fat_layout(struct volume_t * volume, void* buffer)
{
    memcpy(&volume->layout, (uint8_t*)buffer + VOLUME_PARAMETERS, sizeof(struct fat_layout_t));
    if(*((uint8_t*)buffer+SIGNATURE1_POSITION) != BOOT_SIGNATURE1 || *((uint8_t*)buffer+SIGNATURE2_POSITION) != BOOT_SIGNATURE2)
    {
        return -1;
    }

    return 0;
}

struct volume_t* fat_open(struct disk_t* pdisk, uint32_t first_sector)
{
    if(!pdisk || !pdisk->file)
    {
        errno = EFAULT;
        return NULL;
    }

    struct volume_t* volume = calloc(1, sizeof(struct volume_t));

    if(!volume)
    {
        errno = ENOMEM;
        return NULL;
    }

    uint8_t* buffer = calloc(1, 1*BYTES_PER_SECTOR);

    if (!buffer) 
    {
        errno = ENOMEM;
        free(volume);
        return NULL;
    }

    int result = disk_read(pdisk, first_sector, buffer, 1);

    if(result == -1)
    {
        free(buffer);
        free(volume);
        return NULL;
    }

    if(copy_fat_layout(volume, buffer) != 0)
    {
        errno = EINVAL;
        free(buffer);
        free(volume);
        return NULL;
    }

    free(buffer);

    volume->disk = pdisk;
    volume->first_sector = first_sector;

    calculate_fat_sectors(volume, first_sector);
      

    return  volume;
}


int fat_close(struct volume_t* pvolume)
{
    if(!pvolume)
    {
        errno = EFAULT;
        return -1;
    }
    
    free(pvolume);
    
    return 0;
}

