#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of a program.
 * @ac: argument count.
 * @av: argument vector.
 *
 * Return: pointer to the concatenated string, or NULL if it fails.
 */

char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, k, total;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}
	total = 0;
	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			total++;
			j++;
		}
		total++;
	}
	str = (char *)malloc((total + 1) * sizeof(char));
	if (str == NULL)
	{
		return (NULL);
	}
	k = 0;
	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			str[k++] = av[i][j++];
		}
		str[k++] = '\n';
	}
	str[k] = '\0';

	return (str);
}
