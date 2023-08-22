#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
/**
 * print_format - handles printing based on format specifier
 * @format: the format specifier
 * @args: the variable argument list
 * Return: the number of characters printed
 */
int print_format(const char *format, va_list args)
{
	int count = 0;

	switch (*format)
	{
		case 'c':
			{
				char c = (char)va_arg(args, int);

				count += write(1, &c, 1);
			}
			break;
		case 's':
			{
				char *str = va_arg(args, char *);

				if (str == NULL)
					str = "(null)";
				count += write(1, str, strlen(str));
			}
			break;
		default:
			write(1, format - 1, 1);
			count++;
			write(1, format, 1);
			count++;
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
