#include "main.h"

/**
 * _sqrt_recursion - calculates the square root of a number
 * @n: input number
 * Return: square root of the number
 */

int _sqrt_recursion(int n)
{
	int i;

	for (i = 1; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			if (i * i == n)
			{
				return (i);
			}
			if ((n / i) * (n / i) == n)
			{
				return (n / i);
			}
		}
	}

	return (-1);
}
