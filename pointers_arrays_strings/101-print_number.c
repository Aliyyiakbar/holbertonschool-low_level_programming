#include "main.h"

/**
 * print_number - prints an integer using _putchar
 * @n: number to print
 */
void print_number(int n)
{
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		num = (unsigned int)(-(n + 1)) + 1;
	}
	else
	{
		num = (unsigned int)n;
	}

	if (num / 10)
	{
		print_number((int)(num / 10));
	}

	_putchar((num % 10) + '0');
}
