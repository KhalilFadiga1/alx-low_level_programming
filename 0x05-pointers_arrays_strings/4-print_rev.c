#include "main.h"

/**
 * print_rev - print string in a reverse order
 * followed by a new line
 * @s: string to print in reverse order
 */
void print_rev(char *s)
{
	int leng = 0;
	int n;

	while (*s != '\0')
	{
	leng++;
	s++;
	}
	s--;
	for (n = leng; n > 0; n--)
	{
	_putchar(*s);
	s--;
	}
	_putchar('\n');
}
