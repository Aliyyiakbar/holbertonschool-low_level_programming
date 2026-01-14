#include "lists.h"

/**
 * _strlen - returns the length of a string
 * @s: pointer to the string
 *
 * Return: length of the string
 */

int _strlen(const char *s)
{
	int ln = 0;

	while (s[ln] != '\0')
	{
		ln++;
	}

	return (ln);
}

/**
 * add_node_end - adds new node to the end of the linked list
 * @head: pointer to the first node of the linked list
 * @str: content of the link to add header
 *
 * Return: the number of nodes
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *ptr, *tmp;

	if (head == NULL || str == NULL)
	{
		return (NULL);
	}

	tmp = malloc(sizeof(*tmp));
	if (tmp == NULL)
	{
		return (NULL);
	}

	tmp->str = strdup(str);
	if (tmp->str == NULL)
	{
		free(tmp);
		return (NULL);
	}

	tmp->len = _strlen(str);
	tmp->next = NULL;

	if (*head == NULL)
	{
		*head = tmp;
		return (tmp);
	}
	ptr = *head;

	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}

	ptr->next = tmp;

	return (tmp);
}
