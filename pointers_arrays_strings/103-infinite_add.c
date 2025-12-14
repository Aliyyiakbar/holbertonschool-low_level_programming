#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string
 *
 * Return: length
 */
static int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		++len;
	}

	return (len);
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
	int i = _strlen(n1) - 1;
	int j = _strlen(n2) - 1;
	int k = size_r - 1;
	int carry = 0;
	int sum, d1, d2;

	if (size_r <= 0)
	{
		return (0);
	}

	r[k] = '\0';
	k--;

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
		--i;
		--j;
		--k;
	}

	return (r + k + 1);
}
