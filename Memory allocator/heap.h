#ifndef HEAP_H
#define HEAP_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

enum pointer_type_t
{
    pointer_null,
    pointer_heap_corrupted,
    pointer_control_block,
    pointer_inside_fences,
    pointer_inside_data_block,
    pointer_unallocated,
    pointer_valid
};


typedef struct Block
{
    unsigned int hash;
    size_t allocated_memory_size;
    size_t totally_block_size;
    bool is_free;
    struct Block * next;
    struct Block * previous;
} Block;

int heap_setup(void);
void heap_clean(void);

void* heap_malloc(size_t size);
void* heap_calloc(size_t number, size_t size);
void* heap_realloc(void* memblock, size_t count);
void  heap_free(void* memblock);

size_t   heap_get_largest_used_block_size(void);  

enum pointer_type_t get_pointer_type(const void* const pointer);

int heap_validate(void);

#endif