#include "main.h"

/**
 * print_int - prints integers from  va_list
 * @list: the va_list of integers to be printed
 * Return: the number of characters printed
 */

int print_int(va_list list)
{
	int num = va_arg(list, int);
	char buffer[50];

	_itoa(num, buffer);
	return (_puts(buffer));
}

/**
 * print_unsigned - prints unsigned integers from  va_list
 * @list: the va_list of unsigned integers to be printed
 * Return: the number of characters printed
 */

int print_unsigned(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	char buffer[50];

	_itoa(num, buffer);
	return (_puts(buffer));
}
