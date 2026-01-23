#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The NULL terminated string to add to the
 *                end of the file.
 *
 * Return: If the function fails -1.
 *         If the file does not exist the user lacks write
 *         permissions -1, 1 otherwise.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int f;
	ssize_t w;
	size_t ln = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	f = open(filename, O_WRONLY | O_APPEND);

	if (f == -1)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		while (text_content[ln] != '\0')
		{
			++ln;
		}

		w = write(f, text_content, ln);

		if (w == -1)
		{
			close(f);
			return (-1);
		}

		close(f);
		return (1);
	}

	close(f);
	return (1);
}
