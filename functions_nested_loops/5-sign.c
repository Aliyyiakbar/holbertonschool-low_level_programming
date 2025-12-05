#include "main.h"

/**
 * print_sign - solves the problem
 * @n: the input passed by user
 *
 * Return: solution of the problem
 */


int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return 1;
	}
	else if (n == 0)
	{
		_putchar('0');
		return 0;
	}
	else
	{
		_putchar('-');
		return -1;
	}
}
