#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: Character to be written
 * Return: On Succes 1
 * On Error: -1  is returned and errno is set appropriate
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
