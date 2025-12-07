#include "main.h"

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
			{
				_putchar(p + '0');
			}
			else
			{
				_putchar(',');
				_putchar(' ');

				if (p <= 9)
				{
					_putchar(' ');
					_putchar(' ');
				}
				else if (p <= 99)
				{
					_putchar(' ');
				}

				if (p >= 100)
				{
					_putchar((p / 100) + '0');
					_putchar(((p / 10) % 10) + '0');
					_putchar((p % 10) + '0');
				}
				else if (p >= 10)
				{
					_putchar((p / 10) + '0');
					_putchar((p % 10) + '0');
				}
				else
				{
					_putchar(p + '0');
				}
			}
		}
		_putchar('\n');
	}
}
