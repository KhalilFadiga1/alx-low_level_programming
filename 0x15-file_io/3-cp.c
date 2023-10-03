#include <stdlib.h>
#include "main.h"
#include <stdio.h>

void close_file(int fd);
char *create_buffer(char *file);

/**
 * create_buffer - Assigns 1024 bytes to a buf
 * @file: File name of buf to stores the string for
 * Return: Ptr to the newly-assigned buf
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
 * close_file - End File Descriptor
 * @fd: File Descriptor to close
 */
void close_file(int fd)
{
	int a;

	a = close(fd);
	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Duplicates contents of one file to another
 * @argc: Arg counter
 * @argv: Arg vector
 * Return: 0 on success
 * DESCRIPTION: for incorrect arg counter - Exit Code is 97
 * for non-existance of file_from or inability to read - Exit Code is 99
 * for not able to make file_to or write to - Exit Code is 99
 * if file_to or file_from cannot be ended - Exit Code is 100
 */
int main(int argc, char *argv[])
{
	char *buf;
	int frm, to2, rd, wt;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buf = create_buffer(argv[2]);
	frm = open(argv[1], O_RDONLY);
	rd = read(frm, buf, 1024);
	to2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (frm == -1 || rd == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buf);
			exit(99);
		}
		wt = write(to2, buf, rd);
		if (to2 == -1 || wt == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}
		rd = read(frm, buf, 1024);
		to2 = open(argv[2], O_WRONLY | O_APPEND);
	} while (rd > 0);
	free(buf);
	close_file(frm);
	close_file(to2);
	return (0);
}
