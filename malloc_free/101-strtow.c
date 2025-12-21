#include "main.h"
#include <stdlib.h>

/**
 * count_words - counts the number of words in a string
 * @str: input string
 *
 * Return: number of words found in the string
 */
int count_words(char *str)
{
	int i, count, in_word;

	count = 0;
	in_word = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		else
		{
			in_word = 0;
		}
	}
	return (count);
}

/**
 * word_len - determines the length of the next word
 * @str: pointer to the start of a word or spaces
 *
 * Return: length of the word
 */
int word_len(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0' && str[len] != ' ')
	{
		len++;
	}
	return (len);
}

/**
 * dup_word - allocates and duplicates a word substring
 * @str: pointer to the start of the source word
 * @len: length of the word to duplicate
 *
 * Return: pointer to newly allocated word, or NULL on failure
 */
char *dup_word(char *str, int len)
{
	char *w;
	int i;

	w = (char *)malloc((len + 1) * sizeof(char));
	if (w == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len; i++)
	{
		w[i] = str[i];
	}
	w[len] = '\0';
	return (w);
}

/**
 * free_words - frees an array of words up to a given count
 * @words: array of word pointers
 * @n: number of entries to free
 *
 * Return: nothing
 */
void free_words(char **words, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (words[i] != NULL)
		{
			free(words[i]);
		}
	}
	free(words);
}

/**
 * strtow - splits a string into words separated by spaces
 * @str: pointer to input string
 *
 * Return: pointer to an array of strings (words), or NULL if it fails
 */
char **strtow(char *str)
{
	char **words;
	int i, wcount, idx, len;

	if (str == NULL || *str == '\0')
	{
		return (NULL);
	}

	wcount = count_words(str);
	if (wcount == 0)
	{
		return (NULL);
	}

	words = (char **)malloc((wcount + 1) * sizeof(char *));
	if (words == NULL)
	{
		return (NULL);
	}

	idx = 0;
	for (i = 0; i < wcount; i++)
	{
		while (str[idx] == ' ')
		{
			idx++;
		}

		len = word_len(str + idx);
		words[i] = dup_word(str + idx, len);
		if (words[i] == NULL)
		{
			free_words(words, i);
			return (NULL);
		}
		idx += len;
	}
	words[wcount] = NULL;
	return (words);
}
