#include "main.h"

/**
 * get_endianness - Check endianness
 * Return: 0 for big endian, 1 for small endian
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}
