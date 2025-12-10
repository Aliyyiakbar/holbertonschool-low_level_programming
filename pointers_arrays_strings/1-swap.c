#include "main.h"

/**
 * swap_int - swaps the values of params a and b
 * @a: pointer to the int
 * @b: pointer to the int
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
