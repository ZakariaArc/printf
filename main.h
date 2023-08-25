#ifndef _MAIN
#define _MAIN

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct fmt - the structure for formatting data
 * @sym: *sym: a pointer to a character string
 * @fn: the function pointer to a function that takes a va_list as an arg
 */

typedef struct fmt
{
	char *sym;
	int (*fn)(va_list);
} fmt_t;

/**
 * struct flags - the structure for storing the status of different flag options
 * @j: the integer that indicates the maximum number of characters to print
 * @plus: the integer that represents the plus sign option
 * @space: the integer that represents the space option
 * @hash: the integer that represents the hash option
 **/

typedef struct flags
{
	int j;
	int plus;
	int space;
	int hash;
	int l;
	int h;
} flags_t;

typedef struct width
{
	int value;
	int is_zero;
	int is_astreak;
} width_t;

/**
 * struct function_t - holds a function pointer and its base value
 * @base: base value for the function
 * @pfn: the pointer to the function
 **/
typedef struct
{
	int base;
	int (*pfn)(va_list);
} function_t;

int _printf(const char *format, ...);

typedef int (*pfn_t)(va_list);
void get_flags(const char *format, flags_t *flags, int *i);
void get_width(const char *format, width_t *width, int *i);
void get_length(const char *format, flags_t *flags, int *i);
pfn_t get_print(const char *format);
pfn_t get_conversion(const char *format, int *i, va_list args,
					 flags_t *flags, width_t *width);

void parse_flags(flags_t *flags, va_list args_flags,
				 pfn_t pfn, int *printed);
void parse_width(width_t *width, va_list args_width,
				 pfn_t pfn, int *printed);
void parse_length(flags_t *flags, va_list args_flags,
				  pfn_t pfn, int *printed);

int print_char(va_list list);
int print_str(va_list list);
int print_perc(va_list list);

int print_int(va_list list);
int print_unsigned(va_list list);

int print_binary(va_list list);
int print_octal(va_list list);
int print_hex(va_list list);
int print_HEX(va_list list);
int print_addrs(va_list list);

int print_STR(va_list list);
int print_rev(va_list list);
int print_rot13(va_list list);

unsigned int _strlen(char *s);
void reverse_str(char s[]);
void _itoa(long n, char s[]);
int to_base_n(unsigned long num, int base, char s[]);
int num_len_base(long num, int base);

int _putchar(char c);
int _puts(char *str);

#endif
