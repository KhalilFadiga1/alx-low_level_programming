#include "main.h"
#include <stdlib.h>

/**
 * array_range - function that creates array of integers
 * @min: Minimum integer
 * @max: Maximum integer
 * Return: A pointer to a newly created array of integers
 */
int *array_range(int min, int max)
{
	int *a, i = 0;

	if (min > max)
		return (NULL);
	a = malloc(sizeof(int) * (max - min) + sizeof(int));
	if (a == NULL)
		return (NULL);
	while (min <= max)
	{
		a[i] = min;
		i++;
		min++;
	}
	return (a);
}
