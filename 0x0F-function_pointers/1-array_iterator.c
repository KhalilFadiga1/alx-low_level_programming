#include "function_pointers.h"

/**
 * array_iterator - executes a function as a parameter on
 * each element of an array
 * @array: name of array
 * @action: pointer to a function
 * @size: size of an array
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array != NULL && action != NULL && size > 0)
	{
		i = 0;
		while (i < size)
		{
			action(array[i]);
			i++;
		}
	}
}
