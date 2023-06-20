#include <unistd.h>

/**
 * _putchar - Writes the character c to stdout
 * @c: The character to be print
 * Return: On Success 1
 * On error: -1 is returned and errno is set appropriate
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
