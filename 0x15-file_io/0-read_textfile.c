#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - read and print Text File to STDOUT
 * @filename: name of text file to be read
 * @letters: Total Number of Chars to be read
 * Return: If actual number of bytes read and printed - w
 * else 0 if filename is NULL or if function did not work
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t x;
	ssize_t y;
	ssize_t fd;
	char *buffer;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	y = read(fd, buffer, letters);
	x = write(STDOUT_FILENO, buffer, y);
	free(buffer);
	close(fd);
	return (x);
}
