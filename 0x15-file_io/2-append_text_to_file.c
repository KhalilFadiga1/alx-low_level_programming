#include "main.h"

/**
 * append_text_to_file - Addition of characters to file
 * @filename: Specific file to add the text
 * @text_content: Texts to be added
 * Return: 1 if Successful, -1 if otherwise
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file, count_l, rwr;

	if (!filename)
		return (-1);
	file = open(filename, O_WRONLY | O_APPEND);
	if (file == -1)
		return (-1);
	if (text_content)
	{
		for (count_l = 0; text_content[count_l]; count_l++)
			;
		rwr = write(file, text_content, count_l);
		if (rwr == -1)
			return (-1);
	}
	close(file);
	return (1);
}
