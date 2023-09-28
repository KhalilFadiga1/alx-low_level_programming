#include "main.h"

/**
 * clear_bit - Sets the value of a bit at a given index to 0
 * @n: Ptr to the integer to vary
 * @index: Posit of the bit to change
 * Return: 1 if it worked, -1 if it fails
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);
	*n = (~(1UL << index) & *n);
	return (1);
}
