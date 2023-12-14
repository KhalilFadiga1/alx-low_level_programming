#include "main.h"

/**
 * _pow - Calc Base to the Power of a number
 * base: Base Number
 * pow: Exponential vlaue
 * Return: Results of the Calculation
 */
unsigned long int _pow(unsigned int base, unsigned int pow)
{
	unsigned int x;
	unsigned long int val;

	val = 1;
	for (x = 1; x <= pow; x++)
		val *= base;
	return (val);
}

/**
 * print_binary - Prints a num in Binary Digit
 * @n: Integer to be Printed
 */
void print_binary(unsigned long int n)
{
	unsigned long int div, chck;
	char flg;

	flg = 0;
	div = _pow(2, sizeof(unsigned long int) * 8 - 1);
	while (div != 0)
	{
		chck = n & div;
		if (chck == div)
		{
			flg = 1;
			_putchar('1');
		}
		else if (flg == 1 || div == 1)
		{
			_putchar('0');
		}
		div >>= 1;
	}
}
