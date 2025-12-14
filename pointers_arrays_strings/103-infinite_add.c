#include "main.h"

/**
 * f - returns the length of a string
 * @s: string
 * Return: length
 */
int f(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		++i;
	}

	return (i);
}

/**
 * infinite_add - adds two numbers stored as strings
 * @n1: first number string
 * @n2: second number string
 * @r: buffer to store result
 * @size_r: size of buffer r
 *
 * Return: pointer to result in r, or 0 if it doesn't fit
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, j, k, carry, sum, d1, d2;

	if (size_r <= 0)
	{
		return (0);
	}

	i = f(n1) - 1;
	j = f(n2) - 1;

	k = size_r - 1;
	r[k] = '\0';
	k--;

	carry = 0;
	while (i >= 0 || j >= 0 || carry)
	{
		if (k < 0)
		{
			return (0);
		}

		d1 = (i >= 0) ? (n1[i] - '0') : 0;
		d2 = (j >= 0) ? (n2[j] - '0') : 0;
		sum = d1 + d2 + carry;
		r[k] = (sum % 10) + '0';
		carry = sum / 10;
		i--;
		j--;
		k--;
	}

	return (r + k + 1);
}
