#include "file_reader.h" 
#include "tested_declarations.h"
#include "rdebug.h"
#include <errno.h>
#include "tested_declarations.h"
#include "rdebug.h"

struct disk_t* disk_open_from_file(const char* volume_file_name)
{
    if(!volume_file_name)
    {
        errno = EFAULT;
        return NULL;
    }

    struct disk_t* current_disk = calloc(1, sizeof(struct disk_t));
    
    if(!current_disk)
    {
        errno = ENOMEM;
        return NULL;
    }

    current_disk->file = fopen(volume_file_name, "rb");

    if(!current_disk->file)
    {
        free(current_disk);
        return NULL;
    }

    fseek(current_disk->file, 0, SEEK_END);
    long file_size = ftell(current_disk->file);
    if(file_size == -1)
    {   
        disk_close(current_disk);
        return NULL;
    }
    current_disk->sectors_count = file_size/BYTES_PER_SECTOR;

    return current_disk;
}


int disk_read(struct disk_t* pdisk, int32_t first_sector, void* buffer, int32_t sectors_to_read)
{
    if(!pdisk || !pdisk->file || !buffer)
    {
        errno = EFAULT;
        return -1;
    }

    if(first_sector < 0 || sectors_to_read <= 0 || first_sector+sectors_to_read > (int)pdisk->sectors_count)
    {
        errno = ERANGE;
        return -1;
    }

    uint32_t start_disk_bytes = first_sector * BYTES_PER_SECTOR;

    if(fseek(pdisk->file, start_disk_bytes, SEEK_SET) != 0)
    {
        errno = EIO;
        return -1;
    }

    if((int)fread(buffer, BYTES_PER_SECTOR, sectors_to_read, pdisk->file) < sectors_to_read)
    {
        errno = ERANGE;
        return -1;
    }


    return sectors_to_read;
}


int disk_close(struct disk_t* pdisk)
{
    if(!pdisk || !pdisk->file)
    {
        errno = EFAULT;
        return -1;
    }

    fclose(pdisk->file);

    free(pdisk);

    return 0;
}


