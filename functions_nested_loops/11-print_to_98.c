#include <stdio.h>
#include "main.h"

/**
 * print_to_98 - solves the problem
 * @n: the input passed by user
 *
 */

void print_to_98(int n)
{
	if (n >= 98)
	{
		int i;

		for (i = n; i > 98; --i)
		{
			printf("%d, ", i);
		}
	}
	else
	{
		int i;

		for (i = n; i < 98; ++i)
		{
			printf("%d, ", i);
		}
	}
	printf("98\n");
}
