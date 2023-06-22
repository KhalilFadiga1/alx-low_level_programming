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
	printf("Fizz\n, ");
	}
	else if ((i % 5) == 0)
	{
	printf("Buzz\n, ");
	}
	else if ((i % 15) == 0)
	{
	printf("FizzBuzz\n, ");
	}
	else
	{
	printf("%i\n, ", i);
	}
	}
	return (0);
}
