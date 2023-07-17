#include <unistd.h>

/**
 * _putchar - write character c  to the stdout
 * @c: The character to write
 * Return: 1 On Success
 * On Error: -1 is returned and errno is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
