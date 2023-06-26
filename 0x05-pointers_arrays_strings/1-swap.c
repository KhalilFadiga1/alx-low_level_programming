#include "main.h"

/**
 * swap_int - swap the values of two integers
 * @a: The first integer to swap its value
 * @b: Second integer to swap its value
 * Return: Nothing
 */
void swap_int(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
