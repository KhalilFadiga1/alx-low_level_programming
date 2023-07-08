#include "main.h"
#include <stdio.h>

/**
 * _strstr - function that locates a substring
 * @haystack: Input value
 * @needle: Input value
 * Return: 0 (On Success)
 */
char *_strstr(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack++)
	{
		char *one = haystack;
		char *two = needle;

		while (*one == *two && *two != '\0')
		{
		one++;
		two++;
		}
		if (*two == '\0')
		{
		return (haystack);
		}
	}
	return (NULL);
}
