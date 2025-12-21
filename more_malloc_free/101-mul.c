#include "main.h"
#include <stdlib.h>

/**
 * print_error - prints Error and exits with 98
 */
void print_error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * validate_number - checks if a string is a valid positive number
 * @s: string to validate
 */
void validate_number(char *s)
{
	int i = 0;

	if (!s || s[0] == '\0')
		print_error();

	for (; s[i]; i++)
	{
		if (!_isdigit(s[i]))
			print_error();
	}
}

/**
 * big_multiply - multiply two big number strings
 * @s1: the first big number string
 * @s2: the second big number string
 * @len: output length of result array
 *
 * Return: pointer to digits array (each cell 0..9)
 */
char *big_multiply(char *s1, char *s2, int *len)
{
	char *r;
	int l1, l2, i, j, a, b, carry;

	l1 = _strlen(s1);
	l2 = _strlen(s2);
	*len = l1 + l2;

	r = malloc(sizeof(char) * (*len));
	if (!r)
		print_error();

	for (i = 0; i < *len; i++)
		r[i] = 0;

	for (i = l1 - 1; i >= 0; i--)
	{
		a = s1[i] - '0';
		carry = 0;

		for (j = l2 - 1; j >= 0; j--)
		{
			b = s2[j] - '0';
			carry += r[i + j + 1] + (a * b);
			r[i + j + 1] = carry % 10;
			carry /= 10;
		}
		r[i + j + 1] += carry;
	}

	return (r);
}

/**
 * main - multiply two positive numbers
 * @argc: the number of arguments
 * @argv: the argument vector
 *
 * Return: Always 0 on success.
 */
int main(int argc, char **argv)
{
	char *r;
	int len, i, started = 0;

	if (argc != 3)
		print_error();

	validate_number(argv[1]);
	validate_number(argv[2]);

	r = big_multiply(argv[1], argv[2], &len);

	for (i = 0; i < len; i++)
	{
		if (r[i] != 0)
			started = 1;
		if (started)
			_putchar(r[i] + '0');
	}

	if (!started)
		_putchar('0');

	_putchar('\n');
	free(r);
	return (0);
}
