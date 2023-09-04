#include "main.h"

/**
 * create_file - Function that creates a new file
 * @filename: An address to the file name to be created
 * @text_content: A pointer to characters to write to the new file
 * Return: -1 for failure and 1 for success
 */
int create_file(const char *filename, char *text_content)
{
	int ab, x, count = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (count = 0; text_content[count];)
			count++;
	}
	ab = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	x = write(ab, text_content, count);
	if (ab == -1 || x == -1)
		return (-1);
	close(ab);
	return (1);
}
