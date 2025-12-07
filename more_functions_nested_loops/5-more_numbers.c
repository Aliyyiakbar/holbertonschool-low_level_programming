#include "main.h"

/**
 * print_num - prints a number from 0 to 14
 * @n: number to print
 */
static void print_num(int n)
{
	if (n >= 10)
		_putchar((n / 10) + '0');
	_putchar((n % 10) + '0');
}

/**
 * more_numbers - prints 10 times the numbers from 0 to 14
 *
 * Return: nothing
 */
void more_numbers(void)
{
	int line, num;

	for (line = 0; line < 10; line++)
	{
		for (num = 0; num <= 14; num++)
			print_num(num);
		_putchar('\n');
	}
}
