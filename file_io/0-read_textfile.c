#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to
 *                 the POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters
 *         it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t f, r, w;
	char *s;

	if (filename == NULL)
	{
		return (0);
	}

	f = open(filename, O_RDONLY);

	if (f == -1)
	{
		return (0);
	}

	s = malloc(sizeof(char) * letters);

	if (s == NULL)
	{
		close(f);
		return (0);
	}

	r = read(f, s, letters);

	if (r == -1)
	{
		free(s);
		close(f);
		return (0);
	}

	w = write(STDOUT_FILENO, s, r);
	free(s);
	close(f);

	return (w);
}
