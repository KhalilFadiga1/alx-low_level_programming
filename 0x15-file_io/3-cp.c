#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_10_stat(int stat, int fd, char *filename, char mode);
/**
 * main - Copy file content to another
 * @argc: Arg Count
 * @argv: Arg vector
 * Return: if successful 1, exit if it fails
 */
int main(int argc, char *argv[])
{
	unsigned int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	int dest, s, w, c_s, c_d, n_r = 1024;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s", "Usage: cp file_from file_to\n");
		exit(97);
	}
	s = open(argv[1], O_RDONLY);
	check_10_stat(s, -1, argv[1], 'O');
	dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	check_10_stat(dest, -1, argv[2], 'W');
	while (n_r == 1024)
	{
		n_r = read(s, buf, sizeof(buf));
		if (n_r == -1)
			check_10_stat(-1, -1, argv[1], 'O');
		w = write(s, buf, n_r);
		if (w == -1)
			check_10_stat(-1, -1, argv[2], 'W');
	}
	c_s = close(s);
	check_10_stat(c_s, s, NULL, 'C');
	c_d = close(dest);
	check_10_stat(c_d, dest, NULL, 'C');
	return (0);
}

/**
 * check_10_stat - verify if a File can be Open or Close
 * @stat: File descriptor
 * @filename: File Name
 * @fd: File desc
 * @mode: Opening a file or Closing a file
 */
void check_10_stat(int stat, int fd, char *filename, char mode)
{
	if (stat == -1 && mode == 'C')
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
	else if (mode == 'O' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	else if (mode == 'W' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", filename);
		exit(99);
	}
}
