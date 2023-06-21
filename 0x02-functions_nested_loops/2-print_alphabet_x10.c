#include "main.h"

/**
 * print_alphabet_x10 - Print 10 times alphabets in lowercase, followed a new line
 * Return: Nothing
 */
void print_alphabet_x10(void)
{
	int i = 0;
	char c;

	while (i < 10)
	{
		for (c = 'a'; c <= 'z'; c++)
			_putchar(c);
		i++;
	}
	_putchar('\n');
}
