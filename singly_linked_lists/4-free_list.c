#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head: pointer to the first node of the linked list
 *
 */

void free_list(list_t *head)
{
	if (head == NULL)
	{
		return;
	}
	free(head->len);
	free(head->str);
	free_list(&head->next);
}
