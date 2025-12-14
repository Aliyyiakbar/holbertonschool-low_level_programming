#include "main.h"

/**
 * leet - encodes a string into 1337
 * @str: string to encode
 *
 * Return: pointer to str
 */
char *leet(char *str)
{
	int i, j;
	char letters[] = "aAeEoOtTlL", nums[] = "4433007711";

	i =  0;

	while (str[i] != '\0')
	{
		j = 0;
		while (letters[j] != '\0')
		{
			if (str[i] == letters[j])
			{
				str[i] = nums[j];
			}
			++j;
		}
		++i;
	}

	return (str);
}
