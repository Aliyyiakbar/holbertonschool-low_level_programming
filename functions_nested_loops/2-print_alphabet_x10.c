#include "main.h"

/**
 * print_alphabet_x10 - Prints the solution for the task.
 *
 **/

void print_alphabet_x10(void)
{
	char i, c;

	for (i = 1; i <= 10; ++i)
	{
		for (c = 'a'; c <= 'z'; ++c)
		{
			_putchar(c);
		}
		_putchar('\n');
	}
}
