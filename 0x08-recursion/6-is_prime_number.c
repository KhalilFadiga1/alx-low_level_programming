#include "main.h"

/**
 * is_prime_number - say if a number is prime number or not
 * @n: The number to evaluate
 * @i: Iterator
 * Return: 1 if the number is prime, 0 if not
 */
int actual_prime(int n, int i);

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (actual_prime(n, n  - 1));
}

/**
 * actual_prime - calculate if a number is prime recursively
 * @n: The number to evaluate
 * @i: The iterator
 * Return: 1 if n is prime, 0 if not
 */
int actual_prime(int n, int i)
{
	if (i == 1)
		return (1);
	else if (n % i == 0 && i > 0)
		return (0);
	else
		return (actual_prime(n, i - 1));
}
