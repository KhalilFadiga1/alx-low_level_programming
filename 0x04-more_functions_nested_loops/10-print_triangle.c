#include "main.h"

/**
 * print_triangle - print a triangle followed by a new line
 * @size: The size of the triangle
 * Return: Nothing
 */
void print_triangle(int size)
{
	int x, y, z;

	if (size <= 0)
	{
	_putchar('\n');
	}
	else
	{
	for (x = 1; x <= size; x++)
	{
	for (z = size; z >= 1; z--)
	{
	_putchar(' ');
	}
	for (y = 1; y <= x; y++)
	{
	_putchar('#');
	}
	_putchar('\n');
	}
	}
}
