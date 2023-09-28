#include "main.h"

/**
 * binary_to_uint - Changes a Binary integer to Unsigned int
 * @b: Str having the Binary integer
 * Return: The changed integer
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int dec_val = 0;
	int x;

	if (!b)
		return (0);
	for (x = 0; b[x]; x++)
	{
		if (b[x] < '0' || b[x] > '1')
			return (0);
		dec_val = 2 * dec_val + (b[x] - '0');
	}
	return (dec_val);
}
