#include <stdio.h>

int _putchar(char c);

void print_alphabet(void)
{
	for (char c = 'a'; c <= 'z' ++c)
	{
		_putchar(c);
	}
	_putchar('\n');
}