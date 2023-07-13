#include <unistd.h>
#include "main.h"

/**
 * _putchar - write a character c to the std
 * @c: The character to write
 * Return: 1 On Success
 * On Error: -1 is returned and errno is set appropriate
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
