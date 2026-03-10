#include "io.h"

#include "memory.h"
#include "string.h"

void io_printc(const char c)
{
    write(IO_H__STDOUT, &c, 1);
}

void io_printlnc()
{
    io_printc('\n');
}

void io_print_sz(const char * str, const int size)
{
    for (int i = 0; i < size; i++)
    {
        io_printc(str[i]);
    }
}

void io_print(const char * str)
{
    io_print_sz(str, str_size(str));
}

void io_println_sz(const char * str, const int size)
{
    io_print_sz(str, size);
    io_printlnc();
}

void io_println(const char * str)
{
    io_println_sz(str, str_size(str));
}

const char * io_read(const char * message)
{
    if (str_size(message) > 0)
    {
        io_print(message);
        io_print(": ");
    }

    char * sBuffer = mem_alloc(IO_H__MAX_BUFFER_SIZE);
    read(IO_H__STDIN, sBuffer, IO_H__MAX_BUFFER_SIZE);
    return sBuffer;
}
