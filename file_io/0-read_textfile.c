#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters
 *         it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd, r_bytes, w_bytes;
	char *buffer;

	if (filename == NULL)
	{
			return (0);
	}

	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		return (0);
	}

	buffer = malloc(sizeof(char) * letters);

	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	r_bytes = read(fd, buffer, letters);

	if (r_bytes == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	w_bytes = write(STDOUT_FILENO, buffer, r_bytes);
	free(w_bytes);
	close(fd);

	return (w_bytes);
}
