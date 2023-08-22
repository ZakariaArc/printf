#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - the custom printf function
 * @format: a format string
 * @...: the variable arguments
  * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int div, b;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'b')
			{
				div = va_arg(args, int);
				while (div / 2 != 0)
				{
					div = div / 2;
					b = div % 2;
				}
				return (b);
			}
		}
	}
	va_end(args);
	return (0);
}
