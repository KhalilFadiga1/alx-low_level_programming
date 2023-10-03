#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * error_file - verify whether a file can be open or not
 * @file_from: source file
 * @file_to: destination file
 * @argv: arg pointer
 */
void error_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - Verify a code for Holberton School Students
 * @argc: Arg Counter
 * @argc: Arg pointer
 * Return: 0 if success
 */
int main(int argc, char *argv[])
{
	char buffer[1024];
	int file_frm, file_t, err_close;
	ssize_t nwr, nchars;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_frm file_t");
		exit(97);
	}
	file_frm = open(argv[1], O_RDONLY);
	file_t = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(file_frm, file_t, argv);
	nchars = 1024;
	while (nchars == 1024)
	{
		nchars = read(file_frm, buffer, 1024);
		if (nchars == -1)
			error_file(-1, 0, argv);
		nwr = write(file_t, buffer, nchars);
		if (nwr == -1)
			error_file(0, -1, argv);
	}
	err_close = close(file_frm);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_frm);
		exit(100);
	}
	err_close = close(file_t);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_frm);
		exit(100);
	}
	return (0);
}
