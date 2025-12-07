#include "main.h"

/**
 * print_cell - prints a cell (after the first column) in the times table
 * @n: value to print
 */
static void print_cell(int n)
{
	_putchar(',');
	_putchar(' ');

	if (n < 10)
	{
		_putchar(' ');
		_putchar(' ');
		_putchar(n + '0');
	}
	else if (n < 100)
	{
		_putchar(' ');
		_putchar((n / 10) + '0');
		_putchar((n % 10) + '0');
	}
	else
	{
		_putchar((n / 100) + '0');
		_putchar(((n / 10) % 10) + '0');
		_putchar((n % 10) + '0');
	}
}

/**
 * print_times_table - prints the n times table, starting with 0
 * @n: the table size
 *
 * Description: if n is < 0 or > 15, the function prints nothing.
 */
void print_times_table(int n)
{
	int i, j, p;

	if (n < 0 || n > 15)
		return;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			p = i * j;
			if (j == 0)
				_putchar('0');
			else
				print_cell(p);
		}
		_putchar('\n');
	}
}
