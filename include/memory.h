#ifndef NEXUS_MEMORY_H
#define NEXUS_MEMORY_H

#include <stddef.h>

#define MEMORY_SIZE 1024

typedef struct
{
    size_t offset;

    size_t size;

    int allocated;

} MemoryBlock;


typedef struct
{
    unsigned char memory[MEMORY_SIZE];

    MemoryBlock blocks[MEMORY_SIZE];

    size_t block_count;

} MemoryManager;


void initialise_memory(
    MemoryManager *manager
);


void *memory_allocate(
    MemoryManager *manager,
    size_t size
);


int memory_free(
    MemoryManager *manager,
    void *pointer
);


size_t memory_used(
    const MemoryManager *manager
);


void print_memory(
    const MemoryManager *manager
);

#endif