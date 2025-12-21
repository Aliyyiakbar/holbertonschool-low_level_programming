#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers from min to max
 * @min: minimum value
 * @max: maximum value
 *
 * Return: pointer to the newly created array, or NULL on failure
 */

int *array_range(int min, int max)
{
	int i, size, *arr;

	if (min > max)
	{
		return (NULL);
	}

	size = max - min + 1;
	arr = malloc_checked(size * sizeof(int));

	for (i = 0; i < size; i++)
	{
		arr[i] = min + i;
	}

	return (arr);
}
