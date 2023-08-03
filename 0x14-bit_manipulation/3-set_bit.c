#include "main.h"

/**
 * set_bit - Set the value of a bit to 1 at a given index
 * @n: The given bit number
 * @index: The index to set the bit integer
 * Return: 1 On Success or -1 if otherwise
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);
	*n = ((1UL << index) | *n);
	return (1);
}
