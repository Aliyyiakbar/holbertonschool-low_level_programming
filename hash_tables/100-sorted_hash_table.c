#include "hash_tables.h"

/**
 * shash_node_create - creates a sorted hash node
 * @key: key string
 * @value: value string
 *
 * Return: pointer to new node or NULL
 */
shash_node_t *shash_node_create(const char *key, const char *value)
{
	shash_node_t *node;

	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
	{
		return (NULL);
	}

	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (NULL);
	}

	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (NULL);
	}

	node->next = NULL;
	node->sprev = NULL;
	node->snext = NULL;

	return (node);
}

/**
 * sorted_insert - inserts node into sorted linked list by key (ASCII)
 * @ht: hash table
 * @node: node to insert
 *
 * Return: void
 */
void sorted_insert(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *cur;

	if (ht->shead == NULL)
	{
		ht->shead = node;
		ht->stail = node;
		return;
	}

	cur = ht->shead;
	while (cur != NULL && strcmp(cur->key, node->key) < 0)
	{
		cur = cur->snext;
	}

	if (cur == ht->shead)
	{
		node->snext = ht->shead;
		ht->shead->sprev = node;
		ht->shead = node;
		return;
	}

	if (cur == NULL)
	{
		node->sprev = ht->stail;
		ht->stail->snext = node;
		ht->stail = node;
		return;
	}

	node->snext = cur;
	node->sprev = cur->sprev;
	cur->sprev->snext = node;
	cur->sprev = node;
}

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the array
 *
 * Return: pointer to new table or NULL
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	if (size == 0)
	{
		return (NULL);
	}

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
	{
		return (NULL);
	}

	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		ht->array[i] = NULL;
	}

	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - adds/updates an element in the sorted hash table
 * @ht: hash table
 * @key: key (non-empty)
 * @value: value (can be empty, must be duplicated)
 *
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	shash_node_t *cur, *node;
	char *dup;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
	{
		return (0);
	}

	idx = key_index((const unsigned char *)key, ht->size);
	cur = ht->array[idx];

	while (cur != NULL)
	{
		if (strcmp(cur->key, key) == 0)
		{
			dup = strdup(value);
			if (dup == NULL)
			{
				return (0);
			}
			free(cur->value);
			cur->value = dup;
			return (1);
		}
		cur = cur->next;
	}

	node = shash_node_create(key, value);
	if (node == NULL)
	{
		return (0);
	}

	node->next = ht->array[idx];
	ht->array[idx] = node;

	sorted_insert(ht, node);

	return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: hash table
 * @key: key string
 *
 * Return: value string or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int idx;
	shash_node_t *cur;

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

/**
 * shash_table_print - prints the sorted hash table (ascending by key)
 * @ht: hash table
 *
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *cur;
	int first;

	if (ht == NULL)
	{
		return;
	}

	printf("{");
	cur = ht->shead;
	first = 1;

	while (cur != NULL)
	{
		if (first == 0)
		{
			printf(", ");
		}
		printf("'%s': '%s'", cur->key, cur->value);
		first = 0;
		cur = cur->snext;
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - prints the sorted hash table (descending by key)
 * @ht: hash table
 *
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *cur;
	int first;

	if (ht == NULL)
	{
		return;
	}

	printf("{");
	cur = ht->stail;
	first = 1;

	while (cur != NULL)
	{
		if (first == 0)
		{
			printf(", ");
		}
		printf("'%s': '%s'", cur->key, cur->value);
		first = 0;
		cur = cur->sprev;
	}

	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: hash table
 *
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *cur, *next;

	if (ht == NULL)
	{
		return;
	}

	cur = ht->shead;
	while (cur != NULL)
	{
		next = cur->snext;
		free(cur->key);
		free(cur->value);
		free(cur);
		cur = next;
	}

	free(ht->array);
	free(ht);
}
