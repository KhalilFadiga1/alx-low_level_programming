#include "main.h"

/**
 * get_bit - Return a bit at a given index
 * @n: The number to evaluate
 * @index: The given index
 * Return: The bit value
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > 63)
		return (-1);
	bit_val = (n >> index) & 1;
	return (bit_val);
}
