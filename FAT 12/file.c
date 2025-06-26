#include "file_reader.h"
#include "tested_declarations.h"
#include "rdebug.h"
#include "errno.h"
#include "stdlib.h"
#include <string.h>
#include <unistd.h>  
#include "tested_declarations.h"
#include "rdebug.h"

#define CLUSTER_END 0xFFF8
#define ENTRY_MASK 0x0FFF

uint16_t find_next_cluster(struct volume_t *volume, uint16_t cluster) 
{
    if (!volume) 
    {
        errno = EFAULT;
        return CLUSTER_END; 
    }

    uint32_t fat_start = volume->calculated.fat_start_sector;
    uint32_t number_bytes_in_sector = volume->layout.bytes_per_sector;

    uint32_t fat_offset = cluster + (cluster >> 1);
    uint32_t target_sector = fat_start + (fat_offset / number_bytes_in_sector);
    uint32_t target_sector_offset = fat_offset % number_bytes_in_sector;

    uint8_t buffer[BYTES_PER_SECTOR];

    if (disk_read(volume->disk, target_sector, buffer, 1) != 1) 
    {
        errno = EIO;
        return CLUSTER_END;
    }

    uint8_t low_byte  = buffer[target_sector_offset];
    uint8_t high_byte;

    if (target_sector_offset == number_bytes_in_sector - 1) 
    {
        if (disk_read(volume->disk, target_sector + 1, buffer, 1) != 1)
        {
            errno = EIO;
            return CLUSTER_END;
        }
        high_byte = buffer[0];
    } 
    else 
    {
        high_byte = buffer[target_sector_offset + 1];
    }

    uint16_t entry = (uint16_t)low_byte | ((uint16_t)high_byte << 8);
    if (cluster & 1) 
    {
        entry = entry >> 4;
    } 
    else 
    {

        entry = entry & ENTRY_MASK;
    }

    return entry;
}

struct file_t
{
    struct volume_t* volume;

    uint32_t start_cluster;
    uint32_t current_cluster;
    uint32_t file_size;
    uint32_t bytes_offset;
    uint32_t bytes_per_cluster;
    uint8_t *cluster_storage;
};

static struct file_t* file_create(struct volume_t* vol, uint32_t first_cluster, uint32_t size) 
{
    struct file_t* opened_file = calloc(1, sizeof(*opened_file));
    if (!opened_file) 
    {
        errno = ENOMEM;
        return NULL;
    }

    opened_file->volume = vol;
    opened_file->start_cluster = first_cluster;
    opened_file->current_cluster = first_cluster;
    opened_file->file_size = size;
    opened_file->bytes_offset = 0;
    opened_file->bytes_per_cluster = vol->calculated.bytes_per_cluster;

    opened_file->cluster_storage = malloc(opened_file->bytes_per_cluster);
    if (!opened_file->cluster_storage) 
    {
        free(opened_file);
        errno = ENOMEM;
        return NULL;
    }

    return opened_file;
}


struct file_t* file_open(struct volume_t* vol, const char* fname) 
{
    if (!vol || !fname) 
    {
        errno = EFAULT;
        return NULL;
    }

    struct dir_t* root_dir = dir_open(vol, "\\");
    if (!root_dir) 
    {
        return NULL;
    }

    struct dir_entry_t entry;
    while (dir_read(root_dir, &entry) == 0) 
    {
        if (strcmp(entry.name, fname) == 0) 
        {
            if (entry.is_directory) 
            {
                dir_close(root_dir);
                errno = EISDIR;
                return NULL;
            }

            struct file_t* current_file = file_create(vol, entry.first_cluster, entry.size);
            if (!current_file) 
            {
                dir_close(root_dir);
                return NULL; 
            }

            uint32_t first_sector_number = vol->calculated.data_start_sector + (current_file->current_cluster - 2) * vol->layout.sectors_per_cluster;

            int n = disk_read(vol->disk, first_sector_number, current_file->cluster_storage, vol->layout.sectors_per_cluster);
            if (n != vol->layout.sectors_per_cluster) 
            {
                free(current_file->cluster_storage);
                free(current_file);
                errno = EIO;
                dir_close(root_dir);
                return NULL;
            }

            dir_close(root_dir);
            return current_file;
        }
    }

    dir_close(root_dir);
    errno = ENOENT;
    return NULL;
}



int file_close(struct file_t* stream)
{
    if (!stream) 
    {
        errno = EFAULT;
        return -1;
    }
    free(stream->cluster_storage);
    free(stream);
    return 0;
}

static int32_t calculate_position(struct file_t* stream, int32_t offset, int whence) 
{
    int32_t target_position;
    
    switch (whence) 
    {
        case SEEK_SET:
            target_position = offset;
            break;
        case SEEK_CUR:
            target_position = (int32_t)stream->bytes_offset + offset;
            break;
        case SEEK_END:
            target_position = (int32_t)stream->file_size + offset;
            break;
        default:
            errno = EINVAL;
            return -1;
    }
    
    if (target_position < 0 || target_position > (int32_t)stream->file_size) 
    {
        errno = ENXIO;
        return -1;
    }
    
    return target_position;
}

static int navigate_and_load_cluster(struct file_t* stream, uint32_t target_position)
 {
    uint32_t bytes_per_cluster = stream->bytes_per_cluster;
    uint32_t clusters_to_skip = target_position / bytes_per_cluster;

    uint16_t current_cluster_number = stream->start_cluster;
    for (uint32_t i = 0; i < clusters_to_skip; i++) 
    {
        current_cluster_number = find_next_cluster(stream->volume, current_cluster_number);
        if (current_cluster_number < 2 || current_cluster_number >= CLUSTER_END) 
        {
            errno = EIO;
            return -1;
        }
    }
    
    stream->current_cluster = current_cluster_number;

    uint32_t data_area_start = stream->volume->calculated.data_start_sector;
    uint32_t sectors_per_cluster = stream->volume->layout.sectors_per_cluster;
    uint32_t target_sector = data_area_start + ((current_cluster_number - 2) * sectors_per_cluster);
    
    if (disk_read(stream->volume->disk, target_sector, stream->cluster_storage, (int32_t)sectors_per_cluster) != (int32_t)sectors_per_cluster)
    {
        errno = EIO;
        return -1;
    }
    
    return 0;
}

int32_t file_seek(struct file_t* stream, int32_t offset, int whence) 
{
    if (!stream) 
    {
        errno = EFAULT;
        return -1;
    }
    
    if (whence != SEEK_SET && whence != SEEK_CUR && whence != SEEK_END) 
    {
        errno = EINVAL;
        return -1;
    }
    
    int32_t target_position = calculate_position(stream, offset, whence);
    if (target_position == -1)
    {
        return -1;
    }

    stream->bytes_offset = (uint32_t)target_position;
    
    if (navigate_and_load_cluster(stream, (uint32_t)target_position) != 0) 
    {
        return -1;
    }
    
    return target_position;
}


static uint32_t calculate_bytes_to_read(struct file_t *stream, size_t bytes_remaining_to_read) 
{
    uint32_t position_in_cluster = stream->bytes_offset % stream->bytes_per_cluster;
    uint32_t remaining_in_cluster = stream->bytes_per_cluster - position_in_cluster;
    uint32_t remaining_in_file = stream->file_size - stream->bytes_offset;
    
    uint32_t bytes_to_copy = remaining_in_cluster < bytes_remaining_to_read ? remaining_in_cluster : bytes_remaining_to_read;
    
    if (bytes_to_copy > remaining_in_file) 
    {
        bytes_to_copy = remaining_in_file;
    }
    
    return bytes_to_copy;
}

static int move_to_next_cluster(struct file_t *stream) 
{
    uint16_t next_cluster = find_next_cluster(stream->volume, stream->current_cluster);
    if (next_cluster < 2 || next_cluster >= CLUSTER_END) 
    {
        errno = EIO;
        return -1;
    }
    
    stream->current_cluster = next_cluster;
    
    uint32_t data_area_start = stream->volume->calculated.data_start_sector;
    uint32_t sectors_per_cluster = stream->volume->layout.sectors_per_cluster;
    uint32_t next_sector = data_area_start + ((next_cluster - 2) * sectors_per_cluster);
    
    if (disk_read(stream->volume->disk, next_sector, stream->cluster_storage, (int32_t)sectors_per_cluster) != (int32_t)sectors_per_cluster)
    {
        errno = EIO;
        return -1;
    }
    
    return 0;
}


size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream) 
{
    if (!ptr || size == 0 || nmemb == 0 || !stream) 
    {
        errno = EFAULT;
        return (size_t)-1;
    }
    
    size_t bytes_requested = size * nmemb;
    size_t bytes_actually_read = 0;
    
    while (bytes_actually_read < bytes_requested && stream->bytes_offset < stream->file_size) 
    {
        uint32_t bytes_to_copy = calculate_bytes_to_read(stream, bytes_requested - bytes_actually_read);
        

        
        uint32_t position_in_cluster = stream->bytes_offset % stream->bytes_per_cluster;
        memcpy((char*)ptr + bytes_actually_read,
               stream->cluster_storage + position_in_cluster,
               bytes_to_copy);
        
        stream->bytes_offset += bytes_to_copy;
        bytes_actually_read += bytes_to_copy;
        

        if (position_in_cluster + bytes_to_copy == stream->bytes_per_cluster && stream->bytes_offset < stream->file_size) 
        {
            if (move_to_next_cluster(stream) != 0) 
            {
                break;
            }
        }
    }
    
    return bytes_actually_read / size;
}
