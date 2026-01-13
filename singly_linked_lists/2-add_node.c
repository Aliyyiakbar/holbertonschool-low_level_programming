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

	tmp->str = str;
	tmp->len = strlen(str);
	tmp->next = NULL;
	(*head)->next = tmp;
	return tmp;
}
