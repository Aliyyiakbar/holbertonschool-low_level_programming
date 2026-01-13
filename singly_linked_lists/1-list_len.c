#include "lists.h"

/**
 * list_len - number of elements in a linked list
 * @h: pointer to the first node of the linked list
 *
 * Return: the number of nodes
 */

size_t list_len(const list_t *h)
{
	size_t c = 0;

	while (h)
	{
		c += 1;
		h = h->next;
	}
	return (c);
}
