#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: the character to print
 * Return: on success 1
 *         on error, -1 is returned, and errno is set appropriately
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a given string with new line
 * @str: the given string
 * Return: the count of characters printed
 */
 
int _puts(char *str)
{
	int i = 0;

	for (; str[i]; i++)
		_putchar(str[i]);
	return (i);
}
