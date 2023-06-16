#include <stdio.h>
/**
 * main - A program that prints the lowercase and uppercase alphabets
 * Return: Always 0 (success)
 */
int main(void)
{
	int lowerLetters = 'a';
	int upperLetters = 'A';

	while (lowerLetters <= 'z')
	{
		putchar(lowerLetters);
		lowerLetters += 1;
	}
	while (upperLetters <= 'Z')
	{
		putchar(upperLetters);
		upperLetters += 1;
	}
	putchar('\n');
	return (0);
}
