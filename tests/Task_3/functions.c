#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
int print_number(int n);
int print_format(const char *format, va_list args);
int print_binary(va_list args);

/**
 * print_number - prints a number
 * @n: the number to print
 * Return: the number of characters printed
 */
int print_number(int n)
{
	int count = 0;
	char digit;

	if (n == 0)
	{
		count += write(1, "0", 1);
		return (count);
	}

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
 * print_binary - prints an unsigned int in binary
 * @args: the variable argument list
 * Return: the number of characters printed
 */
int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int count = 0;
	unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);
	int found_one = 0;

	while (mask > 0)
	{
		if (num & mask)
		{
			found_one = 1;
			count += write(1, "1", 1);
		}
		else if (found_one)
		{
			count += write(1, "0", 1);
		}
		mask >>= 1;
	}

	if (!found_one)
		count += write(1, "0", 1);

	return (count);
}

/**
 * print_hex - prints an unsigned int in hexadecimal
 * @args: the variable argument list
 * @uppercase: flag to print in uppercase
 * Return: the number of characters printed
 */
int print_hex(va_list args, int uppercase)
{
	unsigned int num = va_arg(args, unsigned int);
	char *hex_digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	char hex_buffer[sizeof(unsigned int) * 2 + 1];
	int count = 0;
	int i;

	hex_buffer[sizeof(hex_buffer) - 1] = '\0';

	for (i = sizeof(hex_buffer) - 2; i >= 0; i--)
	{
		hex_buffer[i] = hex_digits[num % 16];
		num >>= 4;
	}

	count += write(1, hex_buffer, sizeof(hex_buffer) - 1);
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
		case 'b':
			count += print_binary(args);
			break;
		case 'u':
			{
				unsigned int num = va_arg(args, unsigned int);

				count += print_number(num);
			}
			break;
		case 'o':
			{
				unsigned int num = va_arg(args, unsigned int);
				char octal_buffer[sizeof(unsigned int) * 4 + 1];
				int idx = sizeof(octal_buffer) - 1;

				octal_buffer[idx] = '\0';

				do {
					octal_buffer[--idx] = (num & 7) + '0';
					num >>= 3;
				} while (num);

				count += write(1, octal_buffer + idx, sizeof(octal_buffer) - idx - 1);
			}
			break;
		case 'x':
			count += print_hex(args, 0);
			break;
		case 'X':
			count += print_hex(args, 1);
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

/**
 * print_number_unsigned - prints an unsigned number
 * @n: the unsigned number to print
 * Return: the number of characters printed
 */
