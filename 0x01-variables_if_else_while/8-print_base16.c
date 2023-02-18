#include <stdio.h>
/**
 * main - Entry point
 * Return: 0 (success)
 */
int main(void)
{
	char c;
	int d;

	c = 'a';
	d = 0;
	while((c <= 'f') && (d <= 9))
	{
		putchar(d);
		d++;
		putchar(c);
		c++;
	}
	putchar('\n');
	return (0);
}
