#include "main.h"

/**
 * print_to_98 - Prints all natural numbers from 0 to 98
 * @n: The number to start printing from
 * Return: Nothing
 */
void print_to_98(int n)
{
	if (n <= 98)
	{
	for (; n <= 98; n++)
	{
	if (n == 98)
	{
	printf("%d", n);
	printf('\n');
	break
	}
	else
	{
	printf("%d, ", n);
	}
	}
	}
	if (n >= 98)
	{
	for (; n >= 98; n--)
	{
	if (n == 98)
	{
	printf("%d", n);
	printf("\n");
	break
	}
	else
	{
	printf("%d, ", n);
	}
	}
	}
}
