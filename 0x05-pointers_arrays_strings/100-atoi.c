#include "main.h"

/**
 * _atoi - function that convert a string to an integer
 * @s: string to be converted
 * Return: 0 (On Success)
 */
int _atoi(char *s)
{
	int x, y, z, len, m, digit;

	x = y = z = m = 0;
	len = digit = 0;

	while (s[len] != '\0')
		len++;
	while (x < len && m == 0)
	{
		if (s[x] == '-')
			++y;
		if (s[x] >= '0' && s[x] <= '9')
		{
			digit = s[x] - '0';
			if (y % 2)
				digit = -digit;
			z = z * 10 + digit;
			m = 1;
			if (s[x + 1] < '0' || s[x + 1] > '9')
				break;
			m = 0;
		}
		x++;
	}
	if (m == 0)
		return (0);
	return (z);
}

