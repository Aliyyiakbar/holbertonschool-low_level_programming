#include "main.h"

/**
 * close_fd - closes a file descriptor and exits on failure
 * @fd: file descriptor to close
 *
 * Return: void
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * error - prints an error message and exits with a code
 * @code: exit code
 * @file: filename to print
 * @fd1: fd to close or -1
 * @fd2: fd to close or -1
 * @msg: message format expecting %s
 *
 * Return: void
 */
void error(int code, const char *file, int fd1, int fd2, const char *msg)
{
	dprintf(STDERR_FILENO, msg, file);

	if (fd1 != -1)
	{
		close_fd(fd1);
	}

	if (fd2 != -1)
	{
		close_fd(fd2);
	}

	exit(code);
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 (Success))
 */
int main(int argc, char *argv[])
{
	int from, to;
	ssize_t r, w;
	char buf[1 << 10];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	from = open(argv[1], O_RDONLY);
	if (from == -1)
	{
		error(98, argv[1], -1, -1, "Error: Can't read from file %s\n");
	}
	to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (to == -1)
	{
		error(99, argv[2], from, -1, "Error: Can't write to %s\n");
	}
	while ((r = read(from, buf, 1 << 10)))
	{
		w = write(to, buf, r);
		if (w != r)
		{
			error(99, argv[2], from, to, "Error: Can't write to %s\n");
		}
	}
	if (r == -1)
	{
		error(98, argv[1], from, to, "Error: Can't read from file %s\n");
	}
	close_fd(from);
	close_fd(to);

	return (0);
}
