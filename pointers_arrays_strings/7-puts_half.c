#include "main.h"

/**
 * puts_half - prints the second half of a string
 * @str: the string to print
 */
void puts_half(char *str)
{
	int len = 0;
	int i;

	while (str[len] != '\0')
	{
		++len;
	}

    if (len % 2 == 0)
	{
		i = len / 2;
	}
    else
	{
		i = (len + 1) / 2;
	}

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		++i;
	}

	_putchar('\n');
}
