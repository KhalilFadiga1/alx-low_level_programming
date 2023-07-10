#include "main.h"
#include <unistd.h>

/**
 * _putchar - write a character c to the stdout
 * @c: The character to be written
 * Return: 1 on Success
 * On Error: -1 is returned and errno is set appropriate
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
