#include "main.h"

/**
 * clear_bit - Set the value of bit to 0 at given index
 * @n: The value ot bit
 * @index: the given index
 * Return: 1 On Success or -1 On error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);
	*n = (~(1UL << index) & *n);
	return (1);
}
