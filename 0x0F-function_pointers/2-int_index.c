#include "function_pointers.h"

/**
 * int_index - searches for an integer
 * @array: name of an array
 * @cmp: pointer to a function
 * @size: number of elements of an array
 * Return: 0 on Success, -1 otherwise
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (size > 0)
	{
		if (array != NULL && cmp != NULL)
		{
			while (i < size)
			{
				if (cmp(array[i]))
					return (i);
				i++;
			}
		}
	}
	return (-1);
}
