#ifndef STRING_H
#define STRING_H

#include <unistd.h>

int str_size(const char * str);

void print_c(const char c);
void print_ln();
void print_str_sz(const char * str, const int size);
void print_str_sz_ln(const char * str, const int size);
char * str_copy(char * dest, const char * src);
void print_str(const char * str);
void print_str_ln(const char * str);

#endif // STRING_H
