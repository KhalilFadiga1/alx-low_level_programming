#include "main.h"

/**
 * binary_to_uint - Converting a Binary Unit into Unsigned Int
 * @b: Ptr to the Binary Digits
 * Return: Converted Unsigned Int or 0 if otherwise
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int value;
	int x;

	value = 0;
	if (!b)
		return (0);
	for (x = 0; b[x] != '\0'; x++)
	{
		if (b[x] != '0' && b[x] != '1')
			return (0);
	}
	for (x = 0; b[x] != '\0'; x++)
	{
		value <<= 1;
		if (b[x] == '1')
			value += 1;
	}
	return (value);
}
