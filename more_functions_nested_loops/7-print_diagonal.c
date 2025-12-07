#include "main.h"

/**
 * print_diagonal - draws a diagonal line on the terminal
 * @n: number of times the character \ should be printed
 *
 * Return: nothing
 */
void print_diagonal(int n)
{
	int line, space;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	for (line = 0; line < n; line++)
	{
		for (space = 0; space < line; space++)
			_putchar(' ');
		_putchar('\\');
		_putchar('\n');
	}
}
