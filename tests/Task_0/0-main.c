#include "main.h"
#include <stdio.h>

int main(void)
{
	int len;

	len = _printf("Lets test printf on a simple sentence.\n");
	_printf("Length:[%d]\n", len);
	_printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am string !");
	_printf("Percent:[%%]\n");
	_printf("Unknown:[%r]\n");
	return (0);
}
