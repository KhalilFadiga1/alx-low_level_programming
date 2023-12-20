#include "main.h"

/**
 * create_file - Make a new file
 * @filename: Name of File created
 * @text_content: File texts
 * Return: 1 if successful, -1 if otherwise
 */
int create_file(const char *filename, char *text_content)
{
	int file, letters_c, rwr;

	if (!filename)
		return (-1);
	file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (file == -1)
		return (-1);
	if (!text_content)
		text_content = "";
	for (letters_c = 0; text_content[letters_c]; letters_c++)
		;
	rwr = write(file, text_content, letters_c);
	if (rwr == -1)
		return (-1);
	close(file);
	return (1);
}
