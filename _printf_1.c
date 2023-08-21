#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * print_format - handles printing based on format specifier
 * @format: the format specifier
 * @args: the variable argument list
 * Return: the number of characters printed
 */
int print_format(const char *format, va_list args)
{
	int count = 0, c;
	char *buffer;

	switch (*format)
	{
		case 'd':
			{
				int d = va_arg(args, int);

				buffer = malloc(sizeof(d));
				c = sprintf(buffer, "%d", d);
				if (c > 0)
					count += write(1, buffer, strlen(buffer));
			}
			break;
			case 'i':
			{
				int i = va_arg(args, int);

				buffer = malloc(sizeof(i));
				c = sprintf(buffer, "%i", i);
				if (c > 0)
					count += write(1, buffer, strlen(buffer));
			}
			break;
		default:
			write(1, format - 1, 1);
			count++;
		write(1, format, 1);
		break;
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
	if (format[0] == '%')
	{
		if (format[1] == '\0' || (format[1] == ' ' && format[2] == '\0'))
			return (-1);
	}

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
