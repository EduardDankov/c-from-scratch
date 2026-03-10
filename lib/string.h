#ifndef STRING_H
#define STRING_H

#include <unistd.h>

int str_size(const char * str);
char * str_copy(char * dest, const char * src);
char * str_concat(const char * dest, const char * src);
int str_compare(const char * lhs, const char * rhs);

#endif // STRING_H
