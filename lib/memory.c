#include "memory.h"

static mem_free_block mem_free_block_list_head = {0, 0};
static const int overhead = sizeof(int);
static const int align_to = 16;

void * mem_alloc(int size)
{
    // Trick to round the size to the nearest multiple of align_to that is larger than size
    // Only works if align_to is a power of 2
    size = (size + sizeof(int) + (align_to - 1)) & - (align_to - 1);

    mem_free_block * block = mem_free_block_list_head.next;
    mem_free_block ** head = &(mem_free_block_list_head.next);

    while (block != 0)
    {
        if (block->size >= size)
        {
            *head = block->next;
            return ((char *)block) + sizeof(int);
        }
        head = &(block->next);
        block = block->next;
    }

    block = (mem_free_block *)sbrk(size);
    block->size = size;

    return ((char *)block) + sizeof(int);
}

void mem_free(void * ptr)
{
    mem_free_block * block = (mem_free_block *)(((char *)ptr) - sizeof(int));
    block->next = mem_free_block_list_head.next;
    mem_free_block_list_head.next = block;
}

