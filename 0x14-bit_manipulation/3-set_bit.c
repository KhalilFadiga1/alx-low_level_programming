#include "main.h"

/**
 * set_bit - Sets at given index of a bit to 1
 * @n: Ptr to the integer to change
 * @index: Posit of the bit  to be change
 * Return: 1 if it worked, otherwise -1
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);
	*n = ((1UL << index) | *n);
	return (1);
}
