#include <stdio.h>

/**
 * main - prints numbers from 0 to 100
 * Return: 0 (Successs)
 */
int main(void)
{
	int i;

	for (i = 0; i <= 100; i++)
	{
	if ((i % 3) == 0)
	{
	printf("Fizz");
	}
	else if ((i % 5) == 0)
	{
	printf("Buzz");
	}
	else if ((i % 15) == 0)
	{
	printf("FizzBuzz");
	}
	else
	{
	printf("%i", i);
	}
	if (i < 100)
	{
	printf(" ");
	}
	}
	printf("\n");
	return (0);
}
