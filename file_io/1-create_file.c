#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: The name of the file to create.
 * @text_content: A NULL terminated string to write to the file.
 *
 * Return: 1 on success, -1 otherwise.
 */

int create_file(const char *filename, char *text_content)
{
	int f, w, ln = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	f = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

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
	}

	close(f);
	return (1);
}
