#include "file_reader.h"
#include "tested_declarations.h"
#include "rdebug.h"
#include "errno.h"
#include "tested_declarations.h"
#include "rdebug.h"


#define DIR_ENTRY_SIZE 32

#define ATTRIBUTES_BYTE 11

#define READ_ONLY_BYTE 0x01
#define FILE_HIDEN_BYTE 0x02
#define SYSTEM_FLAG_BYTE 0x04
#define DIRECTORY_BYTE 0x10
#define ARCHIVED_FLAG_BYTE 0x20

#define END_DIR 0x00
#define DELETED_FILE 0xE5
#define VOLUME_LABEL 0x08

#define FILE_SIZE_READ 28 
#define FIRST_CLASTER_LOW 26
#define FIRST_CLASTER_HIGH 27

struct dir_t* dir_open(struct volume_t* pvolume, const char* dir_path)
{
    if(!pvolume || !dir_path)
    {
        errno = EFAULT;
        return NULL;
    }
    
    if(strcmp(dir_path, "\\") != 0)
    {
        errno = ENOENT;
        return NULL;
    }

    struct dir_t * dir = calloc(1, sizeof(struct dir_t));
    
    if (!dir) 
    {
        errno = ENOMEM;
        return NULL;
    }
      

    dir->volume = pvolume;
    dir->current_entry_index = 0;
    dir->cached_sector_number = UINT32_MAX;

    return dir;
}


void read_filename(uint8_t* file_info, struct dir_entry_t* pentry)
{
    char filename[9] = {0};
    int i;
    for(i = 0; i < 8; i++)
    {
        if(*(file_info+i) == ' ')
        {
            *(filename + i) = '\0';
            break;
        }
        *(filename+i) = *(file_info+i);
    }

    char file_extention [4] = {0};
    int j;
    for(j = 0; j < 3; j++)
    {
        if(*(file_info+8+j) == ' ')
        {
            *(file_extention + j) = '\0';
            break;
        }
        *(file_extention+j) = *(file_info+8+j);
    }

    if (*file_extention) 
    {
        snprintf(pentry->name,sizeof(pentry->name),"%.8s.%.3s",filename,file_extention);
    } 
    else 
    {
        snprintf(pentry->name,sizeof(pentry->name),"%.8s",filename);
    }
}

void notice_attributes(struct dir_entry_t* pentry, uint8_t attributes, uint8_t* file_info)
{
    pentry->size = *(uint32_t*)(file_info + FILE_SIZE_READ);

    pentry->is_readonly  = ((attributes & READ_ONLY_BYTE) != 0);
    pentry->is_hidden    = ((attributes & FILE_HIDEN_BYTE) != 0);
    pentry->is_system    = ((attributes & SYSTEM_FLAG_BYTE) != 0);
    pentry->is_directory = ((attributes & DIRECTORY_BYTE) != 0);
    pentry->is_archived  = ((attributes & ARCHIVED_FLAG_BYTE) != 0);

    pentry->first_cluster = (uint16_t)*(file_info+FIRST_CLASTER_LOW) | ((uint16_t)*(file_info+FIRST_CLASTER_HIGH) << 8);
}


int dir_read(struct dir_t* pdir, struct dir_entry_t* pentry)
{
    if (!pdir || !pentry) 
    {
        errno = EFAULT;
        return -1;
    }


    if (pdir->volume->layout.max_root_dir_entries <= pdir->current_entry_index) 
    {
        return 1;
    }

    uint32_t current_bytes_offset = pdir->current_entry_index * 32;
    uint32_t offset_in_sector = current_bytes_offset % BYTES_PER_SECTOR;
    uint32_t sector = pdir->volume->calculated.root_dir_start_sector + (current_bytes_offset / BYTES_PER_SECTOR);

    if (sector != pdir->cached_sector_number)
    {
        if (disk_read(pdir->volume->disk, sector, pdir->sector_buffer, 1) != 1) 
        {
            errno = EIO;
            return -1;
        }
        pdir->cached_sector_number = sector;
    }

    uint8_t* file_info = pdir->sector_buffer + offset_in_sector;

    if (file_info[0] == END_DIR) 
    {
        return 1;
    }

    uint8_t attributes = *(file_info+ATTRIBUTES_BYTE);
                          
    if (*(file_info) == DELETED_FILE || (attributes & VOLUME_LABEL)) 
    {
        pdir->current_entry_index++;
        return dir_read(pdir, pentry);
    }

    read_filename(file_info, pentry);

    notice_attributes(pentry, attributes, file_info);

    pdir->current_entry_index++;
    return 0;
}



int dir_close(struct dir_t* pdir)
{
    if(!pdir)
    {
        errno = EFAULT;
        return -1;
    }

    free(pdir);

    return 0;
}

