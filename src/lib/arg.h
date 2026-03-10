#ifndef ARG_H
#define ARG_H

#include <unistd.h>

typedef __builtin_va_list arg_va_list;

#define arg_va_start(ap, last_arg)  __builtin_va_start(ap, last_arg)
#define arg_va_arg(ap, type)        __builtin_va_arg(ap, type)
#define arg_va_end(ap)              __builtin_va_end(ap)
#define arg_va_copy(dest, src)      __builtin_va_copy(dest, src)

#endif // ARG_H