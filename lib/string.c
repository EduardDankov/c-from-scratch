#include "string.h" 

int str_size(const char * str)
{
    int size = 0;
    while (*str != 0)
    {
        str++;
        size++;
    }
    return size;
}

char * str_copy(char * dest, const char * src)
{
    char * tmp = dest;
    while ((*dest++ = *src++) != 0);
    return tmp;
}

