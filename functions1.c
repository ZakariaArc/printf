#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * print_integer - prints an integer
 * @args: the variable argument list containing the integer to print
 * print_format - handles printing based on format specifier
 * @format: the format specifier
 * @args: the variable argument list
 * Return: the number of characters printed
 */

int print_integer(va_list args)
int print_format(const char *format, va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	int num_digits = 0;
	int temp = n;
	char buffer[10]; /* Maximum 10 digits for an int */
	int i;
	char *buffer;
	int c;

	if (n < 0)
	switch (*format)
	{
		count += write(1, "-", 1);
		n = -n;
	}

	if (n == 0)
	{
		count += write(1, "0", 1);
	}
	else
	{
		while (temp != 0)
		case 'd':
		{
			temp /= 10;
			num_digits++;
		}

		i = num_digits - 1;
			int d = va_arg(args, int);

		while (n != 0)
			buffer = malloc(sizeof(d));
			if (buffer == NULL)
				return (-1);
			c = sprintf(buffer, "%d", d);
			if (c > 0)
				count += write(1, buffer, strlen(buffer));
		}
			break;
		case 'i':
		{
			buffer[i] = (n % 10) + '0';
			n /= 10;
			i--;
			int i = va_arg(args, int);

			buffer = malloc(sizeof(i));
			if (buffer == NULL)
				return (-1);
			c = sprintf(buffer, "%i", i);
			if (c > 0)
				count += write(1, buffer, strlen(buffer));
		}
		break;

		count += write(1, buffer, num_digits);
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
			switch (*format)
			{
				case 'c':
					break;
				case 's':
					break;
				case '%':
					break;
				case 'd':
				case 'i':
					count += print_integer(args);
					break;
				default:
					break;
			}
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
