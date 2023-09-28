#include "main.h"

/**
 * get_endianness - Verify if a Machine is big or small Endian
 * Return: 0 if it's big and 1 if it is small
 */
int get_endianness(void)
{
	unsigned int x = 1;
	char *a = (char *) &x;

	return (*a);
}
