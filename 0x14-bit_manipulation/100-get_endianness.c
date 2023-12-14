#include "main.h"

/**
 * get_endianness - Checks for Endianness
 * Return: 1 for Big Endian and 0 for Small Endian
 */
int get_endianness(void)
{
	char *y;
	int x;

	x = 1;
	y = (char *)&x;
	return (*y);
}
