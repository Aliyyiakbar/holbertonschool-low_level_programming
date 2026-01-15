#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts new node
 * @h: pointer to the head of the list
 * @idx: index where the new node should be added
 * @n: value to be stored in the new node
 *
 * Return: pointer to the new node, or NULL if it failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *nw, *cur;
	unsigned int i;

	if (h == NULL)
	{
		return (NULL);
	}
	if (idx == 0)
	{
		return (add_dnodeint(h, n));
	}
	cur = *h;
	for (i = 0; i < idx && cur != NULL; ++i)
	{
		if (i == idx - 1)
		{
			nw = malloc(sizeof(dlistint_t));
			if (nw == NULL)
			{
				return (NULL);
			}
			nw->n = n;
			nw->next = cur->next;
			nw->prev = cur;
			if (cur->next != NULL)
			{
				cur->next->prev = nw;
			}
			cur->next = nw;

			return (nw);
		}
		cur = cur->next;
	}

	return (NULL);
}
