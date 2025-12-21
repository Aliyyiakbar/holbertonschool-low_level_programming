#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * strtow - splits a string into words.
 * @str: input string.
 *
 * Return: pointer to an array of strings (words), or NULL if it fails.
 */

char **strtow(char *str)
{
	char **words;
	int i, j, k, word_count, char_count, index;

	if (str == NULL || *str == '\0')
	{
		return (NULL);
	}
	word_count = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
		{
			word_count++;
		}
	}
	if (word_count == 0)
	{
		return (NULL);
	}
	words = (char **)malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
	{
		return (NULL);
	}
	index = 0;
	for (i = 0; i < word_count; i++)
	{
		while (str[index] == ' ')
		{
			index++;
		}
		char_count = 0;
		j = index;
		while (str[j] != ' ' && str[j] != '\0')
		{
			char_count++;
			j++;
		}
		words[i] = (char *)malloc((char_count + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			for (k = 0; k < i; k++)
			{
				free(words[k]);
			}
			free(words);
			return (NULL);
		}
		for (j = 0; j < char_count; j++)
		{
			words[i][j] = str[index + j];
		}
		words[i][char_count] = '\0';
		index += char_count;
	}
	words[word_count] = NULL;

	return (words);
}
