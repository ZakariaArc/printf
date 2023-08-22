#include "main.h"

/**
 * print_number_unsigned - prints an unsigned number
 * @n: the unsigned number to print
 * Return: the number of characters printed
 */
int print_number_unsigned(unsigned int n)
{
	int count = 0;
	char digit;

	if (n == 0)
	{
		count += write(1, "0", 1);
		return (count);
	}

	if (n / 10)
		count += print_number_unsigned(n / 10);

	digit = n % 10 + '0';
	count += write(1, &digit, 1);
	return (count);
}
