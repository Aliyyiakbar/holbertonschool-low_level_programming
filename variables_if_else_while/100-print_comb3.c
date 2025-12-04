#include <stdio.h>

/**
 * main - prints the alphabet in lowercase, followed by a new line.
 *
 * Return: Always 0 (Success)
 **/

int main(void)
{
	int i, j;

	for (i = 0; i <= 9; ++i)
	{
		for (j = i + 1; j <= 9; ++j)
		{
			putchar(i + '0');
			putchar(j + '0');
			if (i * 10 + j != 89)
			{
				putchar(',');
				putchar(' ');
			}
		}
	}

	putchar('\n');

	return (0);
}
