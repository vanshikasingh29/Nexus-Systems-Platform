#include "memory.h"

#include <stdio.h>


void initialise_memory(
    MemoryManager *manager
)
{
    if (manager == NULL)
    {
        return;
    }


    manager->block_count = 1;


    manager->blocks[0].offset = 0;

    manager->blocks[0].size =
        MEMORY_SIZE;

    manager->blocks[0].allocated = 0;
}


void *memory_allocate(
    MemoryManager *manager,
    size_t size
)
{
    if (
        manager == NULL ||
        size == 0
    )
    {
        return NULL;
    }


    for (
        size_t i = 0;
        i < manager->block_count;
        i++
    )
    {
        MemoryBlock *block =
            &manager->blocks[i];


        if (
            !block->allocated &&
            block->size >= size
        )
        {
            size_t remaining =
                block->size - size;


            block->size = size;

            block->allocated = 1;


            if (
                remaining > 0 &&
                manager->block_count < MEMORY_SIZE
            )
            {
                for (
                    size_t j =
                        manager->block_count;
                    j > i + 1;
                    j--
                )
                {
                    manager->blocks[j] =
                        manager->blocks[j - 1];
                }


                manager->blocks[i + 1].offset =
                    block->offset + size;

                manager->blocks[i + 1].size =
                    remaining;

                manager->blocks[i + 1].allocated =
                    0;

                manager->block_count++;
            }


            return
                &manager->memory[
                    block->offset
                ];
        }
    }


    return NULL;
}


int memory_free(
    MemoryManager *manager,
    void *pointer
)
{
    if (
        manager == NULL ||
        pointer == NULL
    )
    {
        return 0;
    }


    for (
        size_t i = 0;
        i < manager->block_count;
        i++
    )
    {
        void *block_address =
            &manager->memory[
                manager->blocks[i].offset
            ];


        if (
            block_address == pointer &&
            manager->blocks[i].allocated
        )
        {
            manager->blocks[i].allocated =
                0;

            return 1;
        }
    }


    return 0;
}


size_t memory_used(
    const MemoryManager *manager
)
{
    if (manager == NULL)
    {
        return 0;
    }


    size_t total = 0;


    for (
        size_t i = 0;
        i < manager->block_count;
        i++
    )
    {
        if (
            manager->blocks[i].allocated
        )
        {
            total +=
                manager->blocks[i].size;
        }
    }


    return total;
}


void print_memory(
    const MemoryManager *manager
)
{
    if (manager == NULL)
    {
        return;
    }


    printf(
        "\nMemory Usage: %zu / %d bytes\n",

        memory_used(manager),

        MEMORY_SIZE
    );
}