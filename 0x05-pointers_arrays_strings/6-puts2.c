#include "main.h"

/**
 * puts2 - funtion should prints only one character out of
 * two, starting with the first one
 * @str: input
 * Return: print
 */
void puts2(char *str)
{
	int longi = 0;
	int t = 0;
	char *y = str;
	int i;

	while (*y != '\0')
	{
	y++;
	longi++;
	}
	t = longi - 1;
	for (i = 0; i <= t; i++)
	{
	if (i % 2 == 0)
	{
	_putchar(str[i]);
	}
	}
	_putchar('\n');
}
