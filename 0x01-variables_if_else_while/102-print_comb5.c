#include <stdio.h>
/**
 * main - Printing all possible combinations of two two digits numbers
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, j;

	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			if (i < j)
			{
				putchar(i + '0');
				putchar(i + '0');
				putchar(' ');
				putchar(j + '0');
				putchar(j + '0');
				if (i != 98 || j != 99)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
