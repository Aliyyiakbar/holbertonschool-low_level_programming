#include <stdio.h>

/**
 * main - prints the alphabet in lowercase, followed by a new line.
 *
 * Return: Always 0 (Success)
 **/

int main(void)
{
	int i, j, k;

	for (i = 0; i <= 9; ++i)
	{
		for (j = i + 1; j <= 9; ++j)
		{
			for (k = j + 1; k <= 9; ++k)
			{
				putchar(i + '0');
				putchar(j + '0');
				putchar(k + '0');
				if (i * 100 + j * 10 + k != 789)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}

	putchar('\n');

	return (0);
}
