#include "main.h"

/**
 * append_text_to_file - Add text at the file end
 * @filename: Pointer to file name
 * @text_content: String to append to file end
 * Return: -1 if failed, no filename, no file or
 * no writing permission or 1 when succeeded
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int x, y, count = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (count = 0; text_content[count];)
			count++;
	}
	x = open(filename, O_WRONLY | O_APPEND);
	y = write(x, text_content, count);
	if (x == -1 || y == -1)
		return (-1);
	close(x);
	return (1);
}
