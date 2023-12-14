#include <stdlib.h>
#include "main.h"

/**
 * clear_bit - Sets The Val of Bit to 0 at a given index
 * @n: The number to make changes
 * @index: Specific Position to effect changes
 * Return: if successful, 1 or -1 for occurance of error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > sizeof(n) * 8)
		return (-1);
	*n &= ~(1 << index);
	return (1);
}
