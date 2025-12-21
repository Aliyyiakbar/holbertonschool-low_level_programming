#include "main.h"
#include <stdlib.h>

/**
 * _malloc_checked - allocates memory and checks for success
 * @b: number of bytes to allocate
 *
 * Return: pointer to allocated memory
 *         exits with status 98 if allocation fails
 */

void *_malloc_checked(unsigned int b)
{
	void *ptr = malloc(b);

	if (ptr == NULL)
	{
		exit(98);
	}
	return (ptr);
}

/**
 * string_nconcat - concatenates two strings, taking at most n bytes from s2
 * @s1: first input string
 * @s2: second input string
 * @n: maximum number of bytes to take from s2
 *
 * Return: pointer to newly allocated concatenated string, or NULL on failure
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = 0, len2 = 0, i;
	char *new_str;

	while (s1 && s1[len1])
	{
		++len1;
	}

	while (s2 && s2[len2])
	{
		++len2;
	}

	if (n >= len2)
	{
		n = len2;
	}

	new_str = _malloc_checked(len1 + n + 1);

	if (!new_str)
	{
		return (NULL);
	}

	for (i = 0; i < len1; i++)
	{
		new_str[i] = s1[i];
	}

	for (i = 0; i < n; i++)
	{
		new_str[len1 + i] = s2[i];
	}
	new_str[len1 + n] = '\0';

	return (new_str);
}
