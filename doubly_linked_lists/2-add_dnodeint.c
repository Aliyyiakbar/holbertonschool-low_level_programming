#include "lists.h"

/**
 * add_dnodeint - returns the number of elements in a linked dlistint_t list
 * @head: pointer to the head of the list
 * @n: element to be added to the doubly linked list
 *
 * Return: the number of nodes
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
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
	tmp->prev = NULL;
	tmp->next = cur;

	if (cur != NULL)
	{
		cur->prev = tmp;
	}

	*head = tmp;

	return (tmp);
}
