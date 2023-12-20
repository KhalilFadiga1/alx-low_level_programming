#include "main.h"

/**
 * read_textfile - Reads a text and prints it to the stdout
 * @filename: Name of File to read the text from
 * @letters: Total chars to be read and print
 * Return: Number of characters read and printed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	int file;
	ssize_t lenw, lenr;

	if (filename == NULL)
		return (0);
	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		close(file);
		return (0);
	}
	lenr = read(file, buf, letters);
	close(file);
	if (lenr == -1)
	{
		free(buf);
		return (0);
	}
	lenw = write(STDOUT_FILENO, buf, lenr);
	free(buf);
	if (lenr != lenw)
		return (0);
	return (lenw);
}
