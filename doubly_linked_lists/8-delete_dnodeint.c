#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index
 * @head: pointer to the head of the list
 * @index: index of the node to be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *cur;
	unsigned int i;

	if (head == NULL || *head == NULL)
	{
		return (-1);
	}

	cur = *head;
	if (index == 0)
	{
		*head = cur->next;
		if (*head != NULL)
		{
			(*head)->prev = NULL;
		}
		free(cur);
		return (1);
	}

	for (i = 0; i < index && cur != NULL; ++i)
	{
		cur = cur->next;
	}

	if (cur == NULL)
	{
		return (-1);
	}

	cur->prev->next = cur->next;
	if (cur->next != NULL)
	{
		cur->next->prev = cur->prev;
	}

	free(cur);
	return (1);
}
