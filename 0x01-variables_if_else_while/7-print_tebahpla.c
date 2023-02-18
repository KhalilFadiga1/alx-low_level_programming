#include <stdio.h>
#include <stdlib.h>
/**
 * main - a program that prints all alphabets in reverse order
 * Result: 0 (Successful)
 */
int main(void)
{
	int ch;

	ch = 'z';
	while (ch > 'a')
	{
		putchar(ch);
		ch--;
	}
	putchar('\n');
	return (0);
}
