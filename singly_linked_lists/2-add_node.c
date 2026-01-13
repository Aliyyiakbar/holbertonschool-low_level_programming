#include "lists.h"

/**
 * add_node - adds new node to linked list
 * @head: pointer to the first node of the linked list
 * @str: content of the link to add header
 *
 * Return: the number of nodes
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *tmp;

	if (head == NULL || str == NULL)
	{
		return NULL;
	}

	tmp = malloc(sizeof(*tmp));

	if (tmp == NULL)
	{
		return NULL;
	}

	tmp->str = strdup(str);

	if (tmp->str == NULL)
	{
		free(tmp);
		return NULL;
	}

	tmp->len = strlen(str);
	tmp->next = (*head);
	(*head) = tmp;

	return tmp;
}
