#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head: pointer to the first node of the linked list
 *
 */

void free_list(list_t *head)
{
	list_t *cur, *nxt;

	if (head == NULL)
	{
		return;
	}

	cur = head;
	while (cur != NULL)
	{
		nxt = cur->next;
		free(cur->str);
		free(cur);
		cur = nxt;
	}
	head = NULL;
}
