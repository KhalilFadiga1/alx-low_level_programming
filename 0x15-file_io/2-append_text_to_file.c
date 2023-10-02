#include "main.h"

/**
 * append_text_to_file - Adds text to the end of afile
 * @filename: ptr to the file name
 * @text_content: Chars to be added to the file
 * Return: If the function works 1, or if it fails or filename is empty
 * or file does not exist or user do not have permit -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int m, n, length = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}
	m = open(filename, O_WRONLY | O_APPEND);
	n = write(m, text_content, length);
	if (m == -1 || n == -1)
		return (-1);
	close(m);
	return (1);
}
