#include "main.h"

/**
 * set_bit  - Funcs that sets the value of the bit to 1
 * at a specific position
 * @n: Number of bytes
 * @index: Specific to make exact changes
 * Return: if successful, 1 or -1 for failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int stbt;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	stbt = 1 << index;
	*n = *n | stbt;
	return (1);
}
