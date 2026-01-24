#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key
 * @ht: The hash table to look into
 * @key: The key whose value you want to retrieve
 *
 * Return: The value associated with the element,
 * or NULL if key couldn't be found
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *cur;
	unsigned long int idx;

	if (ht == NULL || key == NULL || *key == '\0')
	{
		return (NULL);
	}
	idx = key_index((const unsigned char *)key, ht->size);
	cur = ht->array[idx];
	while (cur != NULL)
	{
		if (strcmp(cur->key, key) == 0)
		{
			return (cur->value);
		}
		cur = cur->next;
	}
	return (NULL);
}
