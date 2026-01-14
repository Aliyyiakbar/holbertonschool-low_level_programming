#include "lists.h"

/**
 * add_node_end - adds new node to the end of the linked list
 * @head: pointer to the first node of the linked list
 * @str: content of the link to add header
 *
 * Return: the number of nodes
 */

list_t *add_node_end(list_t **head, const char *str)
{
	if ((*head) == NULL || str == NULL)
	{
		return (NULL);
	}

	while ((*head)->next != NULL)
	{
		(*head) = (*head)->next;
	}
	(*head)->next->str = strdup(str);
	(*head)->next->len = _strlen(str);
	(*head)->next->next = NULL;

	return (*head);
}
