#include "main.h"
#include <unistd.h>

/**
 * _putchar - Write character c to the stdout
 * @c: The character to write to stdout
 * Return: 1 On Success
 * ON Error: -1 if failed and set errno appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
