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
 * _realloc - reallocates a memory block
 * @ptr: pointer to the memory previously allocated
 * @old_size: size of the allocated memory
 * @new_size: new size of the memory block
 *
 * Return: pointer to the reallocated memory block, or NULL on failure
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int copy_size, i;

	if (new_size == old_size)
	{
		return (ptr);
	}

	if (ptr == NULL)
	{
		return (_malloc_checked(new_size));
	}

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = _malloc_checked(new_size);

	if (new_ptr == NULL)
	{
		return (NULL);
	}

	copy_size = old_size < new_size ? old_size : new_size;

	for (i = 0; i < copy_size; ++i)
	{
		((char *)new_ptr)[i] = ((char *)ptr)[i];
	}

	free(ptr);

	return (new_ptr);
}
