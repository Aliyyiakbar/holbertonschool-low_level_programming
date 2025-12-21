#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array, using malloc
 * @nmemb: number of elements
 * @size: size of each element
 *
 * Return: pointer to allocated memory, or NULL on failure
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int i, total_size;
	unsigned char *byte_ptr;

	total_size = nmemb * size;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}

	ptr = malloc(total_size);

	if (ptr == NULL)
	{
		return (NULL);
	}

	byte_ptr = (unsigned char *)ptr;

	for (i = 0; i < total_size; i++)
	{
		byte_ptr[i] = 0;
	}

	return (ptr);
}
