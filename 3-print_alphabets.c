#include <stdio.h>
#include <stdlib.h>
/**
 * main - a program that prints both uppercase and lowercase of alphabets
 * Return - 0 (Success)
 */

int main(void)
{
	int ch = 'a';
	int CH = 'A';

	while ((ch <= 'z') && (CH <= 'Z'))
	{
		putchar(ch);
		putchar(CH);
		ch++;
		CH++;
	}
	putchar('\n');
	return (0);
}
