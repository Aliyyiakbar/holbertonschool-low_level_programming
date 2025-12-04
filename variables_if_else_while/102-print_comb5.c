#include <stdio.h>

/**
 * main - prints the alphabet in lowercase, followed by a new line.
 *
 * Return: Always 0 (Success)
 **/

int main(void)
{
	int i, j, k, l;

	for (i = 0; i <= 9; ++i)
	{
		for (j = i + 1; j <= 9; ++j)
		{
			for (k = j + 1; k <= 9; ++k)
			{
				for (l = k + 1; l <= 9; ++l)
				{
					putchar(i + '0');
					putchar(j + '0');
					putchar(' ');
					putchar(k + '0');
					putchar(l + '0');
					if (i * 1000 + j * 100 + k * 10 + l != 9899)
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}

	putchar('\n');

	return (0);
}
