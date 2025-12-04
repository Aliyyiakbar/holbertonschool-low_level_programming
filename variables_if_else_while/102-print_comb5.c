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
		for (j = 0; j <= 9; ++j)
		{
			int k, l;
			if (i == 0)
			{
				k = 0;
				l = 1;
			}
			else
			{
				k = i + 1;
				l = j + 1;
			}
			for (k = 0; k <= 9; ++k)
			{
				for (l = 1; l <= 9; ++l)
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
