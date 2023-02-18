#include <stdio.h>
#include <stdlib.h>
/**
 * main - a program that prints out alphabets in lowercase
 * Return: 0 (Success)
 */

int main(void)
{
	int ch = 'a';

	while (ch <= 'z')
	{
		putchar(ch);
		ch++;
	}
	putchar('\n');
	return (0);
}

