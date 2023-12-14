#include "main.h"

/**
 * flip_bits - Func that Counts the num of bits to flip
 * to Changed from a number to another
 * @n: First integer
 * @m: Second Integer
 * Return: Number of Flips Changed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int curr;
	unsigned long int exclus = n ^ m;
	int x, count = 0;

	for (x = 63; x >= 0; x--)
	{
		curr = exclus >> x;
		if (curr & 1)
			count++;
	}
	return (count);
}
