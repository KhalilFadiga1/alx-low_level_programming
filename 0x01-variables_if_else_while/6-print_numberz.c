#include <stdio.h>
/**
 * main - A program that prints single digit of base 10 starting from 0
 * Return: Always 0 (success)
 */
int main(void)
{
	int i = 0;

	while (i < 10)
	{
		putchar(i);
		i += 1;
	}
	putchar('\n');
	return (0);
}
