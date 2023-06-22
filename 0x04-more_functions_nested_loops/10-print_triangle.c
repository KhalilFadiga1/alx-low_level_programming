#include "main.h"

/**
 * print_triangle - print a triangle followed by a new line
 * @size: The size of the triangle
 * Return: Nothing
 */
void print_triangle(int size)
{
	int row, hatches, spaces;

	if (size <= 0)
	{
	_putchar('\n');
	}
	else
	{
	for (row = 1; row <= size; row++)
	{
	for (spaces = size; spaces >= 1; spaces--)
	{
	_putchar(' ');
	}
	for (hatches = 1; hatches <= x; hatches++)
	{
	_putchar('#');
	}
	_putchar('\n');
	}
	}
}
