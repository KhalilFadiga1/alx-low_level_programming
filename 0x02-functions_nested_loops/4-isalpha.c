#include "main.h"

/**
 * _isalpha - Check for alphabetic characters
 * @c: The character to be checked
 * Return: 1 for character checked and 0 for any other results
 */
int _isalpha(int c)
{
	if ((c >= 65 && c <= 97) || (c >= 97 && c <= 122))
	{
	return (1);
	}
	return (0);
}
