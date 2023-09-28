#include "main.h"

/**
 * flip_bits - Counts total numbof bits to vary from
 * a number to another
 * @n: Beginning integer
 * @m: Ending integer
 * Return: Total number of bits varied
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int curr;
	int x, count = 0;
	unsigned long int exclus = n ^ m;

	for (x = 63; x >= 0; x--)
	{
		curr = exclus >> x;
		if (curr & 1)
			count++;
	}
	return (count);
}
