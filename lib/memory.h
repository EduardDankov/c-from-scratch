#ifndef MEMORY_H
#define MEMORY_H

#include <unistd.h>

typedef struct mem_free_block
{
    int size;
    struct mem_free_block * next;
} mem_free_block;

void * mem_alloc(int size);
void mem_free(void * ptr);

#endif // MEMORY_H
