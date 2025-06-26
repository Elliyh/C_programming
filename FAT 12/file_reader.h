#ifndef FILE_READER_H
#define FILE_READER_H

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BYTES_PER_SECTOR 512


struct disk_t{
    FILE* file;
    uint32_t sectors_count;
};

struct disk_t* disk_open_from_file(const char* volume_file_name);
int disk_read(struct disk_t* pdisk, int32_t first_sector, void* buffer, int32_t sectors_to_read);
int disk_close(struct disk_t* pdisk);


struct fat_layout_t {
    uint16_t bytes_per_sector;       // 11–12
    uint8_t  sectors_per_cluster;    // 13
    uint16_t reserved_sectors_count; // 14–15
    uint8_t  num_fats;               // 16
    uint16_t max_root_dir_entries;   // 17–18
    uint16_t total_sectors_short;    // 19–20
    uint8_t  media_descriptor;       // 21  
    uint16_t fat_size_sectors;       // 22–23
} __attribute__((packed));


struct fat_calculated {
    uint32_t       fat_start_sector;
    uint32_t       root_dir_start_sector;
    uint32_t       root_dir_sectors;
    uint32_t       data_start_sector;
    uint32_t       bytes_per_cluster;
};

struct volume_t {
    struct disk_t* disk;
    uint32_t       first_sector;
    struct fat_layout_t layout;
    struct fat_calculated calculated;
};


struct volume_t* fat_open(struct disk_t* pdisk, uint32_t first_sector);
int fat_close(struct volume_t* pvolume);

struct file_t;

struct file_t* file_open(struct volume_t* pvolume, const char* file_name);
int file_close(struct file_t* stream);
size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream);
int32_t file_seek(struct file_t* stream, int32_t offset, int whence);

struct dir_t{
    struct volume_t* volume;

    uint32_t current_entry_index; 
    uint32_t cached_sector_number;
    uint8_t sector_buffer[BYTES_PER_SECTOR];
};

struct dir_entry_t {
    char     name[13];        
    uint32_t size;            
    uint8_t  is_archived;      
    uint8_t  is_readonly;     
    uint8_t  is_system;        
    uint8_t  is_hidden;        
    uint8_t  is_directory;     
    uint16_t first_cluster;    
};


struct dir_t* dir_open(struct volume_t* pvolume, const char* dir_path);
int dir_read(struct dir_t* pdir, struct dir_entry_t* pentry);
int dir_close(struct dir_t* pdir);

#endif