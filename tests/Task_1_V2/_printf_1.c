#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int print_number(int n);
int print_format(const char *format, va_list args);

/**
 * print_number - prints a number
 * @n: the number to print
 * Return: the number of characters printed
 */
int print_number(int n)
{
	int count = 0;
	char digit;

	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}

	if (n / 10)
		count += print_number(n / 10);

	digit = n % 10 + '0';

	count += write(1, &digit, 1);
	return (count);
}

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
		case '%':
			count += write(1, "%", 1);
			break;
		case 'd':
		case 'i':
			{
				int num = va_arg(args, int);

				count += print_number(num);
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
