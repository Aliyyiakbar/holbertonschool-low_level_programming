#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head: pointer to the first node of the linked list
 *
 */

void free_list(list_t *head)
{
	while(head->next != NULL)
	{
		free(head->len);
		free(head->str);
		head = head->next;
	}
	head = NULL;
}
