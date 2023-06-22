#include "main.h"

/**
 * print_diagonal - draw a diagonal line
 * @n: Times number
 * Return: Nothing
 */
void print_diagonal(int n)
{
	int a, m = 0;

	if (n <= 0)
	{
	_putchar('\n');
	}
	while (m < n)
	{
	for (a = 0; a < m; a++)
	{
	_putchar(' ');
	}
	_putchar('\\');
	m++;
	_putchar('\n');
	}
}
