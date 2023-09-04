#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - Print read text file to the Standard Output
 * @filename: Text File to be read
 * @letters: Total volume of letters being read
 * Return: x - total number of bytes read but 0 when the function
 * fails or no filename
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t ab;
	ssize_t x;
	ssize_t y;

	ab = open(filename, O_RDONLY);
	if (ab == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	y = read(ab, buf, letters);
	x = write(STDOUT_FILENO, buf, y);
	free(buf);
	close(ab);
	return (x);
}
