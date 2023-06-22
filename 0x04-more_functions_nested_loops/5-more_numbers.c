#include "main.h"

/**
 * more_numbers - prints numbers from 0 to 14 followed by
 * new line
 * Return: Nothing
 */
void more_numbers(void)
{
	int c, i = 0;

	while (i < 10)
	{
	for (c = 0; c <= 14; c++)
	{
	if (c >= 10)
	{
	_putchar('1');
	}
	_putchar((c % 10) + '0');
	}
	i++;
	_putchar('\n');
	}
}
