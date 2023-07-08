#include "main.h"

/**
 * _isupper - Check uppercase alphabet
 * @c: The character to be checked
 * Return: 1 (On success) and  0 if otherwise
 */
int _isupper(int c)
{
	if ((c >= 65) && (c <= 90))
	{
	return (1);
	}
	return (0);
}
