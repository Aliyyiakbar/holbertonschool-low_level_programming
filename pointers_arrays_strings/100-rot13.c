#include "main.h"

/**
 * rot13 - encodes a string using rot13
 * @str: string to encode
 *
 * Return: pointer to str
 */
char *rot13(char *str)
{
	int i, j;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	i = 0;

	while (str[i] != '\0')
	{
		j = 0;
		while (in[j] != '\0')
		{
			if (str[i] == in[j])
			{
				str[i] = out[j];
				j = 52;
			}
			j++;
		}
		i++;
	}

	return (str);
}
