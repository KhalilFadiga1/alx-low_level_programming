#include "main.h"

/**
 * _puts_recursion - functions that prints a string, followed
 * by new line
 * @s: The string to be printed
 */
void _puts_recursion(char *s)
{
	if (*s)
	{
		_putchar(*s);
		_puts_recursion(s + 1);
	}
	else
		_putchar('\n');
}
