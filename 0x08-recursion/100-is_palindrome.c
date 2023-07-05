#include "main.h"

/**
 * is_palindrome - check if a string is a palindrome
 * @s: The string to be evaluated
 * @i: Iterator
 * @len: length of string
 * Return: 1 if it's, 0 if not
 */
int check_pal(char *s, int i, int len);
int _strlen(char *s);

int is_palindrome(char *s)
{
	if (*s == 0)
		return (0);
	return (check_pal(s, 0, _strlen_recursion(s)));
}

/**
 * _strlen_recursion - returns the length of a string
 * @s: The string to be evaluated
 * Return: length of a string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}

/**
 * check_pal - check the characters recursively for palindrome
 * @s: String to check
 * @i: Iterator
 * @len: The length of the string
 * Return: 1 if palindrome, 0 if not
 */
int check_pal(char *s, int i, int len)
{
	if (*(s + i) != *(s + len - 1))
		return (0);
	if (i >= len)
		return (1);
	return (check_pal(s, i + 1, len - 1));
}
