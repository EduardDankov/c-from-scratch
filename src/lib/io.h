#ifndef IO_H 
#define IO_H

#include <unistd.h>

#define IO_H__MAX_BUFFER_SIZE 1024

#define IO_H__STDOUT          1
#define IO_H__STDIN           2

void io_printc(const char c);
void io_printlnc();

void io_print_sz(const char * str, const int size);
void io_print(const char * str);

void io_println_sz(const char * str, const int size);
void io_println(const char * str);

const char * io_read(const char * message);

#endif // IO_H
