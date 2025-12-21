#include "main.h"
#include <stdlib.h>

/**
 * _malloc_checked - allocates memory and checks for success
 * @b: number of bytes to allocate
 *
 * Return: pointer to allocated memory
 *         exits with status 98 if allocation fails
 */

void *_malloc_checked(unsigned int b)
{
	void *ptr = malloc(b);

	if (ptr == NULL)
	{
		exit(98);
	}
	return (ptr);
}

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
	arr = _malloc_checked(size * sizeof(int));

	for (i = 0; i < size; i++)
	{
		arr[i] = min + i;
	}

	return (arr);
}
