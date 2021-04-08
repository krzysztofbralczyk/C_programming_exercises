#ifndef _HEAP_H
#define _HEAP_H

#include <stdio.h>

#define PLOTEK_LENGTH 16

typedef struct memory_manager_t {
    void* memory_start;
    long long int memory_size;
    struct memory_chunk_t* first_memory_chunk;
}memory_manager_t;

typedef struct __attribute__ ((__packed__)) memory_chunk_t {
    struct memory_chunk_t* prev;
    struct memory_chunk_t* next;
    long long int size;
    long long int free;
    long long int checksum;
}memory_chunk_t;

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

int heap_setup(void);
void heap_clean(void);

void* heap_malloc(size_t size);
void* heap_calloc(size_t number, size_t size);
void* heap_realloc(void* memblock, size_t count);
void  heap_free(void* memblock);

size_t heap_get_largest_used_block_size(void);
enum pointer_type_t get_pointer_type(const void* const pointer);
int heap_validate(void);

void* heap_malloc_aligned(size_t count);
void* heap_calloc_aligned(size_t number, size_t size);
void* heap_realloc_aligned(void* memblock, size_t size);

#endif
