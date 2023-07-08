#include "main.h"

/**
 * _strchr - function that locates a character in a string
 * @s: String name
 * @c: Character to be located
 * Return: 0 (on Success)
 */
char *_strchr(char *s, char c)
{
	int m = 0;

	while (s[m] >= '\0')
	{
		if (s[m] == c)
		{
		return (&s[m]);
		}
		m++;
	}
	return (0);
}
