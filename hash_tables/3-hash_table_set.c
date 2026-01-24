#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to the hash table
 *
 * @ht: The hash table you want to add or update the key/value to
 * @key: The key. Cannot be an empty string
 * @value: The value associated with the key. Must be duplicated. Can be an empty string
 *
 * Return: 1 if it succeeded, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *nw, *cur;
	unsigned long int idx;
	char *buf;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
	{
		return (0);
	}

	buf = strdup(value);
	if (buf == NULL)
	{
		return (0);
	}

	idx = key_idx((const unsigned char *)key, ht->size);
	cur = ht->array[idx];

	while (cur != NULL)
	{
		if (strcmp(cur->key, key) == 0)
		{
			free(cur->value);
			cur->value = buf;
			return (1);
		}

		cur = cur->next;
	}

	nw = malloc(sizeof(hash_node_t));
	if (nw == NULL)
	{
		free(buf);
		return (0);
	}

	nw->key = strdup(key);
	if (nw->key == NULL)
	{
		free(buf);
		free(nw);
		return (0);
	}

	nw->value = buf;
	nw->next = ht->array[idx];
	ht->array[idx] = nw;

	return (1);
}