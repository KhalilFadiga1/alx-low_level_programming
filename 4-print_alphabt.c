#include <stdio.h>
#include <stdlib.h>
/**
 * main - a program that prints alphabets in lowercase with exception of q and e
 * Return - 0 (Success)
 */

int main(void)
{
	int ch = 'a';

	if ((ch != 'q') && (ch != 'e'))
	{
		putchar(ch);
		ch++;
	}
	putchar('\n');
	return (0);
}
