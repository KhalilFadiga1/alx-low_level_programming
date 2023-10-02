#include "main.h"

/**
 * create_file - Make a file
 * @filename: Ptr to the file name to be created
 * @text_content: Ptr to Chars to write to the file
 * Return: If the function works 1 and -1 if it fails
 */
int create_file(const char *filename, char *text_content)
{
	int m, fd, count = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (count = 0; text_content[count];)
			count++;
	}
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	m = write(fd, text_content, count);
	if (fd == -1 || m == -1)
		return (-1);
	close(fd);
	return (1);
}
