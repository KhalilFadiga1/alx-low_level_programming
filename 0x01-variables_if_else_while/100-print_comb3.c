#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * Return - (0)
 */
int main(void)
{
	int a;

	for (a = 10; a < 100; a++)
	{
		putchar( a + '0');
		if (a < 99)
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}	
