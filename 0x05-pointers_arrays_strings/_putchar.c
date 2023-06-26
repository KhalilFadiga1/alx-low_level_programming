#include <unistd.h>

/**
 * -putchar - write the character to the stdout
 *  @c: The character to write
 *  Return: On Success (1)
 *  On Error: -1 is returned and errno is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1))
}
