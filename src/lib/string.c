#include "string.h" 

#include "memory.h"

int str_size(const char * str)
{
    int size = 0;
    while (str[size] != '\0')
    {
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

char * str_concat(const char * dest, const char * src)
{
    const int dest_len = str_size(dest);
    const int src_len = str_size(src);
    const int result_len = dest_len + src_len - 1;

    char * result = mem_alloc(result_len);

    int i = 0;
    while (dest[i] != '\0' && i < dest_len)
    {
        result[i] = dest[i];
        i++;
    }

    int j = 0;
    while (src[j] != '\0' && j < src_len && i < result_len)
    {
        result[i] = src[j];
        i++;
        j++;
    }

    return result;
}

int str_compare(const char * lhs, const char * rhs)
{
    const int lhs_len = str_size(lhs);
    const int rhs_len = str_size(rhs);

    if (lhs_len != rhs_len)
    {
        return rhs_len - lhs_len;
    }

    for (int i = 0; i < lhs_len; i++)
    {
        if (lhs[i] < rhs[i])
        {
            return 1;
        }
        if (lhs[i] > rhs[i])
        {
            return -1;
        }
    }
    return 0;
}
