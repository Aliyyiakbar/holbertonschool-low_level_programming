#include "main.h"

/**
 * _atoi - converts a string to an integer.
 * @s: pointer to the string to be converted
 *
 * Return: the integer value of the string
 */

int _atoi(char *s)
{
	int i, sign, is;

	unsigned int res;

	i = 0;
	sign = 1;
	res = 0;
	is = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			is = 1;
			res = res * 10 + (s[i] - '0');
		}
		else if (is)
		{
			break;
		}

		i++;
	}

	return (res * sign);
}
