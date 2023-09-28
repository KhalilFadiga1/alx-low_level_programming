#include "main.h"

/**
 * get_bit - Returns the decimal integer of value of a specific bit
 * @n: Traced number
 * @index: The bit index
 * Return: Decimal value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_value;

	if (index > 63)
		return (-1);
	bit_value = (n >> index) & 1;
	return (bit_value);
}
