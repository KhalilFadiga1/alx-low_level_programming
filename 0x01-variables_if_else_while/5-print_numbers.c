#include <stdio.h>
/**
 * main - A program that prints single unit of base 10
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	while (i < 10)
	{
		putchar(i);
		i += 1;
	}
	putchar('\n');
	return (0);
}
