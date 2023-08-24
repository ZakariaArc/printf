#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * print_integer - prints an integer
 * @args: the variable argument list containing the integer to print
 * Return: the number of characters printed
 */
int print_integer(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	int num_digits = 0;
	int temp = n;
	char buffer[10]; /* Maximum 10 digits for an int */
	int i;

	if (n < 0)
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
		{
			temp /= 10;
			num_digits++;
		}

		i = num_digits - 1;

		while (n != 0)
		{
			buffer[i] = (n % 10) + '0';
			n /= 10;
			i--;
		}

		count += write(1, buffer, num_digits);
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
