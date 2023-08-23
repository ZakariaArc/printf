#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);
/**
 * print_format - handles printing based on format specifier
 * @format: the format specifier
 * @args: the variable argument list
 * Return: the number of characters printed
 */
int print_format(const char *format, va_list args)
{
	int count = 0, c_num;
	char *buffer;

	switch (*format)
	{
		case 'c':
			{
				char c = (char)va_arg(args, int);

				count += write(1, &c, 1);
			}
		case 's':
			{
				char *str = va_arg(args, char *);

				if (str == NULL)
					str = "(null)";
				count += write(1, str, strlen(str));
			}
		case '%':
				count += write(1, "%", 1);
		case 'd':
		case 'i':
			{
				int num = va_arg(args, int);

				buffer = malloc(sizeof(num));
				c_num = sprintf(buffer, "%d", num);
				count += write(1, buffer, strlen(buffer));
			}
		default:
				write(1, format - 1, 1);
				count++;
				write(1, format, 1);
				count++;
	}


	return (count);
}
/**
 * _printf - the custom printf function
 * @format: a format string
 * @...: the variable arguments
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += print_format(format, args);
		}
		else
		{
			write(1, format, 1);
			count++;
		}
			format++;
	}
	va_end(args);
	return (count);
}
