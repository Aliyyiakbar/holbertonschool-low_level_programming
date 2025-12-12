#include "main.h"
#include <stdio.h>

/**
 * print_array - prints n elements of an array of integers
 * @a: the array of integers
 * @n: number of elements to print
 */
void print_array(int *a, int n)
{
	int i;

	n = sizeof(a) / sizeof(a[0]);

	for (i = 0; i < n; ++i)
	{
		printf("%d", a[i]);
		if (i != n - 1)
		{
			printf(", ");
		}
		else
		{
			printf("\n");
		}
	}
}
