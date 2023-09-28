#include "main.h"

/**
 * print_binary - Prints a given decimal number in binary
 * @n: The integer to be converted to binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int curr;
	int a, count = 0;

	for (a = 63; a >= 0; a--)
	{
		curr = n >> a;
		if (curr & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}
