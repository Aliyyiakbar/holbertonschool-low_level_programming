#include <main.h>

/**
 * checker - checks the input number from n to the base
 * @n: number is squared and compared against base
 * @base: base number to check
 * Return: natural square root of number base
 */

int checker(int n, int base)
{
	if (n >= base)
	{
		return (1);
	}
	if (base % n == 0)
	{
		return (0);
	}
	return (checker(n + 1, base));
}

/**
 * int is_prime_number(int n) - return the natural square root of a number n.
 * @n: number to check for square roots.
 * Return: the natural square root of number n
 */

int is_prime_number(int n)
{
	return (checker(2, n));
}
