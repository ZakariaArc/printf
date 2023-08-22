#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#ifndef _MAIN
#define _MAIN

#define BUFF_SIZE 1024

int _printf(const char *format, ...);
int print_format(const char *format, va_list args);

#endif
