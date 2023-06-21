#include "main.h"

/**
 * print_alphabet_x10 - Print 10 times alphabets in lowercase, followed a new line
 * Return: Nothing
 */
void print_alphabet_x10(void)
{
	int i;
	char c;

	i = 0;
	while (i < 10)
	{
		for (c = 'a'; c <= 'z'; c++)
			_putchar(c);
		_putchar('\n');
		i++;
	}
}
