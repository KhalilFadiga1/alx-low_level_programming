#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocation of memory of an array
 * @nmemb: Number of elements of the array
 * @size: Size of array in bytes
 * Return: void
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	int i = 0, l = 0;
	char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);
	l = nmemb * size;
	p = malloc(l);
	if (p == NULL)
		return (NULL);
	while (i < l)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
