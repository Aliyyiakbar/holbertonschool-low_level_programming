#include "hash_tables.h"

/**
 * update_value - updates an existing node value if key matches
 * @head: pointer to list head
 * @key: key to search for
 * @buf: duplicated value to store if found
 *
 * Return: 1 if updated, 0 if not found
 */
int update_value(hash_node_t *head, const char *key, char *buf)
{
	hash_node_t *cur;

	cur = head;
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
	return (0);
}

/**
 * hash_table_set - Adds an element to the hash table
 * @ht: The hash table you want to add or update the key/value to
 * @key: The key. Cannot be an empty string
 * @value: The value associated with the key. Must be duplicated.
 * Can be an empty string.
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *nw;
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
	idx = key_index((const unsigned char *)key, ht->size);
	if (update_value(ht->array[idx], key, buf) == 1)
	{
		return (1);
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
