#include <stdio.h>
#include "main.h"

/**
 * print_last_digit - solves the problem
 * @n: the input passed by user
 *
 * Return: solution of the problem
 */


int print_last_digit(int n)
{
	_putchar((n < 0 ? (-n) % 10 : (n % 10)) + '0');
	return (n < 0 ? (-n) % 10 : (n % 10));
}
