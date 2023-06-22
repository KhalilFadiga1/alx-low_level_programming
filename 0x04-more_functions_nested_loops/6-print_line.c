#include "main.h"

/**
 * print_line - draw a straight line in the terminal
 * @n: The number times the character - be printed
 * Return: Nothing
 */
void print_line(int n)
{
	int i = 0;

	while (i < n)
	{
	_putchar('_');
	i++;
	}
	_putchar('\n');
}
