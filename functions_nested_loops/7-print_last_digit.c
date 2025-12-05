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
	_putchar(_abs(n % 10)+ '0');
	return (n % 10);
}
