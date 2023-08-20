#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
/**
 * print_char - prints a single character
 * @args: the variable argument list containing the character to print
 * Return: the number of characters printed (always 1)
 */

int print_char(va_list args)
{
	char c = (char)va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_string - prints a string
 * @args: the variable argument list containing the string to print
 * Return: the number of characters printed
 */

int print_string(va_list args)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	return (write(1, str, strlen(str)));
}

/**
 * print_percent - prints a percent sign ('%')
 * @args: Unused
 * Return: the number of characters printed (always 1)
 */

int print_percent(va_list args)
{
	(void)args;
	return (write(1, "%", 1));
}

/**
 * print_unknown - prints characters that do not match known format specifiers
 * @format: the pointer to the format specifier that triggered the case
 * Return: the number of characters printed (usually 2)
 */

int print_unknown(const char *format)
{
	return (write(1, format, 2));
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
					count += print_char(args);
					break;
				case 's':
					count += print_string(args);
					break;
				case '%':
					count += print_percent(args);
					break;
				default:
					count += print_unknown(format - 1);
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
