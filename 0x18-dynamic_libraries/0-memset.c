#include "main.h"

/**
 * _memset - fill a block of memory with a specific value
 * @s: Starting address of memory to be filled
 * @b: the desired value
 * @n: the number of bytes to be changed
 * Return: Changed array with new value with n bytes
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i;

	for (i = 0; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
