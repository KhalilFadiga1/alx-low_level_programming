#include "main.h"

/**
 * _strpbrk - function that searches for a string for
 * any of a set of bytes
 * @s: Input value
 * @accept: Input value
 * Return: 0 (On Success)
 */
char *_strpbrk(char *s, char *accept)
{
	int n;

	while (*s)
	{
		for (n = 0; accept[n]; n++)
		{
		if (*s == accept[n])
		{
		return (s);
		}
		}
		s++;
	}
	return ('\0');
}
