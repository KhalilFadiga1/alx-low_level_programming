#include "main.h"

/**
 * get_bit - Funcs which returns the value of a bit
 * at given index
 * @n: The number to search from
 * @index: Position of the bit
 * Return: Value of the specific bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int div, chck;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	div = 1 << index;
	chck = n & div;
	if (chck == div)
		return (1);
	return (0);
}
