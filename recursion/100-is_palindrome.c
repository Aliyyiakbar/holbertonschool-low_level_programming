#include "main.h"

/**
 * checker - checks the input number from n to the base
 * @n: number is squared and compared against base
 * @base: base number to check
 * Return: natural square root of number base
 */

int checker(char *s, int n, int base)
{
	if (n >= base / 2)
	{
		return (1);
	}
	if (s[n] != s[_strlen_recursion(s) - n - 1])
	{
		return (0);
	}

	return (checker(s, n + 1, base));
}

/**
 * is_palindrome - checks if palindrome
 * @s: pointer to the input
 * Return: 1 if palindrome, else 0
 */

int is_palindrome(char *s)
{
	return (checker(s, 0, _strlen_recursion(s)));
}
