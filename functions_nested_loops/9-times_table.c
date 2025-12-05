#include "main.h"

/**
 * times_table - Prints the solution for the task.
 *
 **/

void times_table(void)
{
	int i, j;

	for (i = 0; i <= 9; ++i)
	{
		_putchar('0');
		for (j = 1; j <= 9; ++j)
		{
			int val;

			val = i * j;
			if (val < 10)
			{
				_putchar(',');
				_putchar(' ');
				_putchar(' ');
				_putchar((val % 10) + '0');
			}
			else
			{
				_putchar(',');
				_putchar(' ');
				_putchar((val / 10) + '0');
				_putchar((val % 10) + '0');
			}
		}
		_putchar('\n');
	}
}
