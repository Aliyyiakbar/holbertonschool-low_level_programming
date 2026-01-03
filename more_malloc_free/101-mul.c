#include "main.h"
#include <stdlib.h>

/**
 * is_digit_str - checks if a string contains only digits
 * @s: input string
 *
 * Return: 1 if all chars are digits, 0 otherwise
 */
int is_digit_str(char *s)
{
	int i = 0;

	if (s == NULL || *s == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * str_len - returns the length of a string
 * @s: input string
 *
 * Return: length as int
 */
int str_len(char *s)
{
	int i = 0;

	while (s && s[i])
		i++;
	return (i);
}

/**
 * mul_str - multiplies two positive number-strings and returns result string
 * @s1: first number
 * @s2: second number
 *
 * Return: pointer to newly-allocated string containing the product
 *         (caller must free). On allocation failure, prints "Error\n" and
 *         exits with 98.
 */
char *mul_str(char *s1, char *s2)
{
	int len1 = str_len(s1);
	int len2 = str_len(s2);
	int len = len1 + len2;
	int i, j;
	int *res = NULL;
	char *out = NULL;
	int start = 0;

	res = malloc(sizeof(int) * len);
	if (!res)
	{
		/* allocation error */
		char err[] = "Error\n";
		for (i = 0; err[i]; i++)
			_putchar(err[i]);
		exit(98);
	}

	for (i = 0; i < len; i++)
		res[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		int n1 = s1[i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			int n2 = s2[j] - '0';
			int sum = res[i + j + 1] + (n1 * n2);
			res[i + j + 1] = sum % 10;
			res[i + j] += sum / 10;
		}
	}

	/* skip leading zeros */
	while (start < (len - 1) && res[start] == 0)
		start++;

	out = malloc(sizeof(char) * (len - start + 1));
	if (!out)
	{
		free(res);
		char err[] = "Error\n";
		for (i = 0; err[i]; i++)
			_putchar(err[i]);
		exit(98);
	}

	for (i = start; i < len; i++)
		out[i - start] = res[i] + '0';
	out[len - start] = '\0';

	free(res);
	return (out);
}

/**
 * print_number - prints a null-terminated string using _putchar
 * @s: string to print
 */
void print_number(char *s)
{
	int i = 0;

	while (s[i])
	{
		_putchar(s[i]);
		i++;
	}
	_putchar('\n');
}

/**
 * main - entry point; validates args and prints product of two positive numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, (exits with 98 on error as required)
 */
int main(int argc, char **argv)
{
	char *prod;

	if (argc != 3)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');

		exit(98);
	}

	if (!is_digit_str(argv[1]) || !is_digit_str(argv[2]))
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');

		exit(98);
	}

	prod = mul_str(argv[1], argv[2]);
	if (!prod)
	{
		exit(98);
	}

	print_number(prod);
	free(prod);
	return (0);
}
