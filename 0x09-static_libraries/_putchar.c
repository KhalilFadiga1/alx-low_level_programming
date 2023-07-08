#include <unistd.h>

/**
 * _putchar - write a character c to stdout
 * @c: The character to write
 * Return: 1 (On Success)
 * On Error: -1 is returned and errno is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
