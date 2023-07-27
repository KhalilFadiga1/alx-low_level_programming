#include "main.h"
#include <unistd.h>

/**
 * _putchar - Write a character c to the stdout
 * @c: the character to be written
 *
 * Return: 1 On Success
 * On Error: -1 is returned and errno is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
