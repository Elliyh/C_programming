#include "heap.h"

#include <stdio.h>
#include "custom_unistd.h"
#include "rdebug.h"
#include "string.h"
#include "tested_declarations.h"
#include "tested_declarations.h"
#include "rdebug.h"


#define FENCE_SIZE 1
#define PAGES_AVAILABLE 16384

static void *heap_start = NULL;
static void *heap_end = NULL;
static Block *list_of_blocks = NULL;

unsigned int my_hash_function(Block *block) {
    unsigned int suma = 0;
    unsigned char *bytes = (unsigned char *) block;
    for (size_t i = 0; i < sizeof(Block); i++) {
        suma += bytes[i];
    }
    return suma;
}

int heap_setup(void) {
    void *begin = custom_sbrk(0);

    if (begin == (void *) -1) {
        return -1;
    }

    heap_start = begin;
    heap_end = begin;


    return 0;
}

char *set_fence(Block *current_block, size_t size) {
    char *head_fence = (char *) current_block + sizeof(Block);
    memset(head_fence, 0xAA, FENCE_SIZE);
    char *data = head_fence + FENCE_SIZE;
    char *tail_fence = data + size;
    memset(tail_fence, 0xBB, FENCE_SIZE);

    current_block->allocated_memory_size = size;

    return data;
}

void heap_clean(void) {
    if (!heap_start || !heap_end) {
        return;
    }

    custom_sbrk(-((char *) heap_end - (char *) heap_start));

    heap_start = NULL;
    heap_end = NULL;
    list_of_blocks = NULL;
}


void initialize_block(Block *memory, int required_size) {
    memory->is_free = true;
    memory->totally_block_size = required_size;
    memory->allocated_memory_size = 0;
    memory->next = NULL;
    memory->previous = NULL;
    memory->hash = 0;
    memory->hash = my_hash_function(memory);
}


void add_block(Block *new_block) {
    if (list_of_blocks) {
        Block *current_block = list_of_blocks;
        while (current_block->next) {
            current_block = current_block->next;
        }

        current_block->next = new_block;
        new_block->previous = current_block;
        current_block->hash = 0;
        current_block->hash = my_hash_function(current_block);
    } else {
        list_of_blocks = new_block;
    }
    new_block->hash = 0;
    new_block->hash = my_hash_function(new_block);
}


void *heap_malloc(size_t size) {
    if (size <= 0) {
        return NULL;
    }


    Block *current_block = list_of_blocks;

    while (current_block) {
        if (current_block->is_free == true &&
            current_block->totally_block_size - 2 * FENCE_SIZE - sizeof(Block) >= size) {

            char *data = set_fence(current_block, size);

            current_block->is_free = false;

            current_block->hash = 0;
            current_block->hash = my_hash_function(current_block);

            return (void *) data;
        }
        current_block = current_block->next;
    }

    int required_block_size = size + sizeof(Block) + 2 * FENCE_SIZE;


    void *memory = custom_sbrk(required_block_size);

    if (memory == (void *) -1) {
        return NULL;
    }

    if (heap_start == NULL) {
        heap_start = memory;
    }


    heap_end = (char *) memory + required_block_size;

    Block *new_block = (Block *) memory;
    initialize_block(new_block, required_block_size);
    char *data = set_fence(new_block, size);
    new_block->is_free = false;
    new_block->hash = 0;
    new_block->hash = my_hash_function(new_block);
    add_block(new_block);

    return (void *) data;
}


void *heap_calloc(size_t number, size_t size) {
    if (size <= 0 || number <= 0) {
        return NULL;
    }
    void *data = heap_malloc(number * size);
    if (!data) {
        return NULL;
    }

    for (int i = 0; i < (int) number * (int) size; i++) {
        *((char *) data + i) = 0;
    }
    return data;
}


void *heap_realloc(void *memblock, size_t count) {
    if (!heap_start || !heap_end) {
        return NULL;
    }

    if (count == 0) {
        heap_free(memblock);
    }

    if (!memblock) {
        return heap_malloc(count);
    }

    if (get_pointer_type(memblock) != pointer_valid) {
        return NULL;
    }

    Block *current_block = (Block *) ((char *) memblock - sizeof(Block) - FENCE_SIZE);

    if (count <= current_block->allocated_memory_size) {
        set_fence(current_block, count);
        current_block->allocated_memory_size = count;
        current_block->hash = 0;
        current_block->hash = my_hash_function(current_block);
        return memblock;
    }

    Block *next_block = current_block->next;

    if (next_block && next_block->is_free &&
        count <= (current_block->totally_block_size + next_block->totally_block_size - 2 * FENCE_SIZE - sizeof(Block))) {
        current_block->totally_block_size += next_block->totally_block_size;
        current_block->next = next_block->next;
        if (current_block->next) {
            current_block->next->previous = current_block;
        }
        set_fence(current_block, count);
        current_block->allocated_memory_size = count;
        current_block->hash = 0;
        current_block->hash = my_hash_function(current_block);
        if (current_block->next) {
            current_block->next->hash = 0;
            current_block->next->hash = my_hash_function(current_block->next);
        }

        return memblock;
    }

    if (!current_block->next) {
        int additional_memory_size = count - current_block->allocated_memory_size;
        void *add_new_memory = custom_sbrk(additional_memory_size);
        if (add_new_memory == (void *) -1) {
            return NULL; // xz
        }
        current_block->allocated_memory_size = current_block->allocated_memory_size + additional_memory_size;
        set_fence(current_block, current_block->allocated_memory_size);
        heap_end = (char *) heap_end + additional_memory_size;
        current_block->hash = 0;
        current_block->hash = my_hash_function(current_block);
        return memblock;
    }

    void *new_allocated_memory = heap_calloc(1, count);
    if (!new_allocated_memory) {
        return NULL;
    }

    memcpy(new_allocated_memory, memblock, current_block->allocated_memory_size);
    heap_free(memblock);

    return new_allocated_memory;
}


void heap_free(void *memblock) {
    if (!memblock || memblock < heap_start || memblock > heap_end || get_pointer_type(memblock) != pointer_valid ||
        heap_validate() != 0) {
        return;
    }

    Block *current_block = (Block *) ((char *) memblock - sizeof(Block) - FENCE_SIZE);

    current_block->is_free = true;
    current_block->allocated_memory_size = 0;

    Block *next_block = current_block->next;
    Block *previous_block = current_block->previous;

    if (current_block->previous && current_block->previous->is_free) {
        previous_block->totally_block_size += current_block->totally_block_size;
        previous_block->next = current_block->next;
        if (current_block->next) {
            current_block->next->previous = previous_block;
            current_block->next->hash = 0;
            current_block->next->hash = my_hash_function(current_block->next);
        }
        current_block = previous_block;
    }

    if (current_block->next && current_block->next->is_free) {
        Block *temp_next = current_block->next->next;
        current_block->totally_block_size += next_block->totally_block_size;
        current_block->next = temp_next;
        if (temp_next) {
            temp_next->previous = current_block;
            temp_next->hash = 0;
            temp_next->hash = my_hash_function(temp_next);
        }
    }
    current_block->hash = 0;
    current_block->hash = my_hash_function(current_block);
}

size_t heap_get_largest_used_block_size(void) {
    if (!list_of_blocks || heap_validate() != 0) {
        return 0;
        ;
    }


    size_t max = 0;
    Block *current_block = list_of_blocks;
    while (current_block) {
        if (current_block->is_free == false && current_block->allocated_memory_size > max) {
            max = current_block->allocated_memory_size;
        }
        current_block = current_block->next;
    }

    return max;
}

enum pointer_type_t get_pointer_type(const void *const pointer) {
    if (!pointer) {
        return pointer_null;
    }

    if (heap_validate() != 0) {
        return pointer_heap_corrupted;
    }

    if ((char *) pointer < (char *) heap_start || (char *) pointer >= (char *) heap_end) {
        return pointer_unallocated;
    }

    Block *current_block = list_of_blocks;
    while (current_block) {
        if ((char *) pointer >= (char *) current_block) {
            if ((current_block->next != NULL && (char *) pointer < (char *) current_block->next) ||
                (current_block->next == NULL && (char *) pointer < (char *) heap_end)) {
                if ((char *) pointer < (char *) current_block + sizeof(Block)) {
                    return pointer_control_block;
                }

                if (current_block->is_free == true) {
                    return pointer_unallocated;
                }


                char *start_head_fence = (char *) current_block + sizeof(Block);
                char *end_head_fence = (char *) current_block + sizeof(Block) + FENCE_SIZE;
                char *start_data = (char *) current_block + sizeof(Block) + FENCE_SIZE;
                char *end_data = start_data + current_block->allocated_memory_size;
                char *start_tail_fence = end_data;
                char *end_tail_fence = end_data + FENCE_SIZE;

                if (((char *) pointer >= start_head_fence && (char *) pointer < end_head_fence) ||
                    ((char *) pointer >= start_tail_fence && (char *) pointer < end_tail_fence)) {
                    return pointer_inside_fences;
                } else if ((char *) pointer == start_data) {
                    return pointer_valid;
                } else if ((char *) pointer > start_data && (char *) pointer < end_data) {
                    return pointer_inside_data_block;
                } else {
                    return pointer_unallocated;
                }
            }
        }
        current_block = current_block->next;
    }
    return pointer_unallocated;
}


int heap_validate(void) {
    if (!heap_start || !heap_end) {
        return 2;
    }

    if (heap_start == heap_end) {
        return 0;
    }


    Block *current_block = list_of_blocks;

    if ((char *) current_block < (char *) heap_start || (char *) current_block >= (char *) heap_end) {
        return 3;
    }

    char *previous_block_tail = (char *) heap_start;

    while (current_block) {
        unsigned int old_hash = current_block->hash;
        current_block->hash = 0;
        unsigned int new_hash = my_hash_function(current_block);
        current_block->hash = old_hash;

        if (new_hash != old_hash) {
            return 3;
        }

        if ((char *) current_block < (char *) heap_start || (char *) current_block >= (char *) heap_end) {
            return 3;
        }


        if ((char *) current_block < previous_block_tail) {
            return 3;
        }


        char *current_block_tail = (char *) current_block + current_block->totally_block_size;

        if (current_block_tail > (char *) heap_end) {
            return 3;
        }

        if (current_block->is_free == false) {
            char *head_fence = (char *) current_block + sizeof(Block);
            char *tail_fence =
                    (char *) current_block + sizeof(Block) + FENCE_SIZE + current_block->allocated_memory_size;


            for (int i = 0; i < FENCE_SIZE; i++) {
                if (*(head_fence + i) != (char) 0xAA || *(tail_fence + i) != (char) 0xBB) {
                    return 1;
                }
            }
        }

        if (current_block->next != NULL &&
            ((char *) current_block->next >= (char *) heap_end || (char *) current_block->next < (char *) heap_start)) {
            return 3;
        }
        current_block = current_block->next;
        previous_block_tail = current_block_tail;
    }


    return 0;
}

