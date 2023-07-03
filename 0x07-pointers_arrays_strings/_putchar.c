#include "main.h"
#include <unistd.h>

/**
 * _putchar - write character c to the stdout
 * @c: The character to write
 * Return: 1 on success
 * On Error: -1 on error and errno is set to appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
