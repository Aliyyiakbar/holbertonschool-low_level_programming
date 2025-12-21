#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * _strdup - duplicates a string.
 * @str: string to duplicate.
 *
 * Return: pointer to the duplicated string, or NULL if it fails.
 */

char *_strdup(char *str)
{
	char *dup;
	int i, len;

	if (str == NULL)
	{
		return (NULL);
	}

	len = 0;
	while (str[len] != '\0')
	{
		++len;
	}

	dup = (char *)malloc((len + 1) * sizeof(char));
	if (dup == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		dup[i] = str[i];
	}
	dup[len] = '\0';

	return (dup);
}
