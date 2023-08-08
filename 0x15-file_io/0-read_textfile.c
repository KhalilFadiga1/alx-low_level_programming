#include "main.h"
#include "stdlib.h"

/**
 * read_textfile = Read a text file print to STDOUT
 * @filename: Th name of the file to read from
 * @letters: Number of letters in the file to read
 * Return: w - The actual number of letters read and printed; 0 if
 * filename is NULL or write fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);
	free(buf);
	close(fd);
	return (w);
}
