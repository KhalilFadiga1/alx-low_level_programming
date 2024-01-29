#include "main.h"

/**
 * _memcpy - a function that copies a memory area
 * @dest: Storage memory
 * @src: Copied memory
 * @n: number of bytes
 * Return: dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int x;
	int y = n;

	x = 0;
	while (x < y)
	{
		dest[x] = src[x];
		n--;
		x++;
	}
	return (dest);
}
