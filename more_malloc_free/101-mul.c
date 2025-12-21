#include "main.h"
#include <stdlib.h>

/**
 * print_error - Prints Error and a new line
 *
 * Return: 98
 */
int print_error(void)
{
	int i;
	char msg[] = "Error\n";

	for (i = 0; msg[i] != '\0'; i++)
	{
		_putchar(msg[i]);
	}

	return (98);
}

/**
 * is_digits - Checks if a string contains only digits
 * @s: String to check
 *
 * Return: 1 if all characters are digits, 0 otherwise
 */
int is_digits(char *s)
{
	int i;

	if (s == NULL || s[0] == '\0')
	{
		return (0);
	}

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			return (0);
		}
	}

	return (1);
}

/**
 * _strlen - Returns the length of a string
 * @s: String
 *
 * Return: Length of the string
 */
int _strlen(char *s)
{
	int n;

	n = 0;

	while (s[n] != '\0')
	{
		++n;
	}

	return (n);
}

/**
 * print_number - Prints a big number stored in an int array
 * @res: Array of digits
 * @len: Length of the array
 *
 * Return: Nothing
 */
void print_number(int *res, int len)
{
	int i;

	i = 0;

	while (i < len - 1 && res[i] == 0)
	{
		++i;
	}

	for (; i < len; i++)
	{
		_putchar(res[i] + '0');
	}

	_putchar('\n');
}

/**
 * main - Multiplies two positive numbers
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	char *a, *b;
	int la, lb, len, i, j;
	int *res;

	res = NULL;

	if (argc != 3)
	{
		return (print_error());
	}

	a = argv[1];
	b = argv[2];

	if (is_digits(a) == 0 || is_digits(b) == 0)
	{
		return (print_error());
	}

	la = _strlen(a);
	lb = _strlen(b);
	len = la + lb;

	res = malloc(sizeof(int) * len);
	if (res == NULL)
	{
		return (print_error());
	}

	for (i = 0; i < len; i++)
	{
		res[i] = 0;
	}

	for (i = la - 1; i >= 0; i--)
	{
		int carry = 0;
		int da = a[i] - '0';

		for (j = lb - 1; j >= 0; j--)
		{
			int db = b[j] - '0';
			int idx = i + j + 1;
			int sum = res[idx] + (da * db) + carry;

			res[idx] = sum % 10;
			carry = sum / 10;
		}
		res[i] += carry;
	}

	print_number(res, len);
	free(res);

	return (0);
}
