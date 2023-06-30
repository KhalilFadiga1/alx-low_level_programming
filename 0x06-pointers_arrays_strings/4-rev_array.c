#include "main.h"

/**
 * reverse_array - function that reverses the content of
 * array of integers
 * @a: array name
 * @n: number of elements of the array
 */
void reverse_array(int *a, int n)
{
	int i, j;

	i = 0;
	while (i < n--)
	{
		j = a[i];
		a[i] = a[n];
		a[n] = j;
		i++;
	}
}
