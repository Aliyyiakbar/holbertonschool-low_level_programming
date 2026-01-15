#include "lists.h"

/**
 * add_dnodeint_end - returns adds a new node at the end of a dlistint_t list.
 * @head: pointer to the head of the list
 * @n: element to be added to the doubly linked list
 *
 * Return: the address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *tmp, *cur;

	if (head == NULL)
	{
		return (NULL);
	}

	cur = *head;
	tmp = malloc(sizeof(*tmp));
	if (tmp == NULL)
	{
		return (NULL);
	}

	tmp->n = n;
	tmp->next = NULL;

	if (cur == NULL)
	{
		tmp->prev = NULL;
		*head = tmp;
		return (tmp);
	}

	while (cur->next != NULL)
	{
		cur = cur->next;
	}

	cur->next = tmp;
	tmp->prev = cur;

	return (tmp);
}
