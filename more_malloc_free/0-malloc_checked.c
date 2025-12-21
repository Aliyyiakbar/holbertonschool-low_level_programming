#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - allocates memory and checks for success
 * @b: number of bytes to allocate
 *
 * Return: pointer to allocated memory
 *         exits with status 98 if allocation fails
 */

void *malloc_checked(unsigned int b)
{
	void *ptr = malloc(b);

	if (ptr == NULL)
	{
		exit(98);
	}
	return (ptr);
}
