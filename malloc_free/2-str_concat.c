#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * str_concat - concatenates two strings.
 * @s1: first string.
 * @s2: second string.
 *
 * Return: pointer to the duplicated string, or NULL if it fails.
 */

char *str_concat(char *s1, char *s2)
{
	char *concat;
	int len1, len2, i, j;

	len1 = 0;
	len2 = 0;

	if (s1 != NULL)
	{
		while (s1[len1] != '\0')
		{
			++len1;
		}
	}

	if (s2 != NULL)
	{
		while (s2[len2] != '\0')
		{
			++len2;
		}
	}

	concat = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (concat == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len1; i++)
	{
		concat[i] = s1[i];
	}

	for (j = 0; j < len2; j++)
	{
		concat[i + j] = s2[j];
	}
	concat[len1 + len2] = '\0';

	return (concat);
}
