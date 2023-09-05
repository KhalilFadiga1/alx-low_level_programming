#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void close_file(int ab);
char *create_buffer(char *file);

/**
 * create_buffer - Allocation of 1024 bytes to a buffer
 * @file: Buffer name to store the characters
 * Return: An address to newly-allocated buffer
 */
char *create_buffer(char *file)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);
	if (buf == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}
	return (buf);
}

/**
 * close_file - Endd the file descriptors
 * @ab: Closed file descriptor
 */
void close_file(int fd)
{
	int z;

	z = close(fd);
	if (z == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Duplicates the contents of a file to different file
 * @argc: Argument counter
 * @argv: Argument vector
 * Return: 0 (Always Success)
 */
int main(int argc, char *argv[])
{
	int frm, too, m, n;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buf = create_buffer(argv[2]);
	frm = open(argv[1], O_RDONLY);
	m = read(frm, buf, 1024);
	too = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (frm == -1 || m == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from %s\n", argv[1]);
			free(buf);
			exit(98);
		}
		n = write(too, buf, m);
		if (too == -1 || n == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}
		m = read(frm, buf, 1024);
		too = open(argv[2], O_WRONLY | O_APPEND);
	} while (m > 0);
	free(buf);
	close_file(frm);
	close_file(too);
	return (0);
}
