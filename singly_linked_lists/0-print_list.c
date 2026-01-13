#include "lists.h"

/**
 * print_list - prints all the values of a linked list
 * @h: pointer to the first node of the linked list
 *
 * Return: the number of nodes
 */

size_t print_list(const list_t *h)
{
	size_t c = 1;

	if (h == NULL)
	{
		return (0);
	}

	while (h->next != NULL)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%u] %s\n", h->len, h->str);
		}
		h = h->next;
		c += 1;
	}

	if (h->str == NULL)
	{
		printf("[0] (nil)\n");
	}
	else
	{
		printf("[%u] %s\n", h->len, h->str);
	}
	return (c);
}
