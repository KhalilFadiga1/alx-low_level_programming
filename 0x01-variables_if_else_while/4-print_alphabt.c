#include <stdio.h>
/**
 * main - A program which prints lowercase alphabets exception of q and e
 * Return: Always 0 (Success)
 */
int main(void)
{
	int lower = 'a';

	while (lower <= 'z')
	{
		if (lower == 'q' || lower == 'e')
			continue;
		putchar(lower);
		lower += 1;
	}
	putchar('\n');
	return (0);
}
