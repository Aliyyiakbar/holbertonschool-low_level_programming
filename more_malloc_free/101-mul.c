#include "main.h"
#include <stdlib.h>

/**
 * print_error - prints Error and exits with 98
 */
static void print_error(void)
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
 * @c: character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
static int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: string
 *
 * Return: length
 */
static int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * validate_number - validates that string contains only digits
 * @s: string
 */
static void validate_number(char *s)
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
 * big_multiply - multiplies two digit strings into digit array
 * @s1: number string 1
 * @s2: number string 2
 * @len: output length (l1 + l2)
 *
 * Return: pointer to digit array (each cell 0..9)
 */
static char *big_multiply(char *s1, char *s2, int *len)
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
 * main - multiplies two positive numbers
 * @argc: arg count
 * @argv: arg vector
 *
 * Return: 0 on success
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
