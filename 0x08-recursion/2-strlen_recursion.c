#include "main.h"

/**
 * _strlen_recursion - function that returns the length of
 * string
 * @s: The string to be measured
 * Return: Length of s
 */
int _strlen_recursion(char *s)
{
	int longit = 0;

	if (*s)
	{
		longit++;
		longit += _strlen_recursion(s + 1);
	}
	return (longit);
}
