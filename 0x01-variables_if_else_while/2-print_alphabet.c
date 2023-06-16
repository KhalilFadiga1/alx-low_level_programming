#include <stdio.h>
/**
 * main - A program that prints alphabets in lowercases
 * Return: Always 0 (Success)
 */
int main(void)
{
	int alp = 'a';

	while (alp <= 'z')
	{
		putchar(alp);
		alp += 1;
	}
	putchar('\n');
	return (0);
}


