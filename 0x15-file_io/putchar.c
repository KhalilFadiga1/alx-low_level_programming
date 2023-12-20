#include <unistd.h>

/**
 * _putchar - Write the Character c to the stdout
 * @c: the char to be written
 * Return: 1 if successful
 * On Error: -1 is return and errno is set appropriate
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
