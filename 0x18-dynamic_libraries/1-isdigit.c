#include "main.h"

/**
 * _isdigit - Check for a digit from 0 to 9
 * @c: The number to be checked
 * Return: 1 (On success) and 0 if otherwise
 */
int _isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
	{
	return (1);
	}
	return (0);
}
