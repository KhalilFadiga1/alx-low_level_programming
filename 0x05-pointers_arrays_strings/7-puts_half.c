#include "main.h"

/**
 * puts_half - a function that prints a half string,followed
 * by new line
 * @str - string to be reversed
 */
void puts_half(char *str)
{
	int j = 0;
	int k;

	while (str[j] != '\0')
		j++;
	if (j % 2 == 1)
	{
	k = (j - 1) / 2;
	k += 1;
	}
	else
		k = j / 2;
	for (; k < j; k++)
		_putchar(str[k]);
	_putchar('\n');
}
