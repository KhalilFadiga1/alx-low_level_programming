#include "main.h"
#include <unistd.h>

/**
 * _putchar - write a character c to a stdout
 * @s: The character to write
 * Return: 1 (On Success)
 * On Error: -1 is returned and errno is set appropriate
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
