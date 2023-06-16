#include <stdio.h>
/**
 * main - A program that prints lowercase alphabets in reverse order
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i = 'z';

	do {
		putchar(i);
		i--;
	} while (i >= 'a');
	putchar('\n');
	return (0);
}
