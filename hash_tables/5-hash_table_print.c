#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table
 *
 * @ht: The hash table to print
 */

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *cur;
	unsigned long int i;
	bool f = 1;

	if (ht == NULL)
	{
		return;
	}

	printf("{");

	for (i = 0; i < ht->size; ++i)
	{
		cur = ht->array[i];
		while (cur != NULL)
		{
			if (!f)
			{
				printf(", ");
			}
			printf("'%s': '%s'", cur->key, cur->value);
			f = 0;
			cur = cur->next;
		}
	}

	printf("}\n");
}
