#include "main.h"

/**
 * *_strcat - function that concatenate two strings
 * @dest: First string to join another string to
 * @src: Second string to add to first
 * Return: New string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
