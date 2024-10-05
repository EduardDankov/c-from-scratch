#ifndef OUTPUT_H 
#define OUTPUT_H

#include <unistd.h>

void print_c(const char c);
void print_ln();

void print_str_sz(const char * str, const int size);
void print_str_sz_ln(const char * str, const int size);

void print_str(const char * str);
void print_str_ln(const char * str);

#endif // OUTPUT_H
