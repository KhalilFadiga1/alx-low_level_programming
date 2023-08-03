#include "main.h"
#include <unistd.h>

/**
 * _putchar - Write the character c to the
 * standard output
 * @c: The character to write to the output
 * Return: 1 on success
 * On Error: -1 when fail and set errno appropriately
 */
int _putchar(c)
{
	return (write(1, &c, 1));
}
