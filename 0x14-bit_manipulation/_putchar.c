#include <unistd.h>
#include "main.h"

/**
 * _putchar - Writes a Char C to Stdout
 * @c: Char to output
 * Return: 1 if successful; else -1 is returned and
 * errno is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
