#include "output.h"

#include "string.h"

void print_c(const char c)
{
    write(1, &c, 1);
}

void print_ln()
{
    print_c('\n');
}

void print_str_sz(const char * str, const int size)
{
    for (int i = 0; i < size; i++)
    {
        print_c(str[i]);
    }
}

void print_str_sz_ln(const char * str, const int size)
{
    print_str_sz(str, size);
    print_ln();
}

void print_str(const char * str)
{
    print_str_sz(str, str_size(str));
}

void print_str_ln(const char * str)
{
    print_str_sz_ln(str, str_size(str));
}

