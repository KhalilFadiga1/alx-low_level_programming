#include <stdio.h>
/**
 * main - A program that prints single unit of base 10
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i = 0;

	while (i < 10)
	{
		printf("%d", i);
		i += 1;
	}
	putchar('\n');
	return (0);
}
