#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Makes a Sorted Hash Table
 * @size: The sorted hash table size
 * Return: Ptr to new sorted hash table or NULL if its fails
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *hsh_t;
	unsigned long int x;

	hsh_t = malloc(sizeof(shash_table_t));
	if (hsh_t == NULL)
		return (NULL);
	hsh_t->size = size;
	hsh_t->array = malloc(sizeof(shash_node_t *) * size);
	if (hsh_t->array == NULL)
		return (NULL);
	for (x = 0; x < size; x++)
		hsh_t->array[x] = NULL;
	hsh_t->shead = NULL;
	hsh_t->stail = NULL;
	return (hsh_t);
}

/**
 * shash_table_set - Insert a node to a sorted hash table
 * @ht: Ptr to the table
 * @key: New node key - must be non-empty string
 * @value: Key associated value
 * Return: 1 for success and 0 for failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new, *temp;
	char *val_cpy;
	unsigned long int idx;

	if (ht == NULL || key == NULL || *key == '\0' || value == 0)
		return (0);
	val_cpy = strdup(value);
	if (val_cpy == NULL)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);
	temp = ht->shead;
	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = val_cpy;
			return (1);
		}
		temp = temp->snext;
	}
	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
	{
		free(val_cpy);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(val_cpy);
		free(new);
		return (0);
	}
	new->value = val_cpy;
	new->next = ht->array[idx];
	ht->array[idx] = new;
	if (ht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
	}
	else
	{
		temp = ht->shead;
		while (temp->snext != NULL && strcmp(temp->snext->key, key) < 0)
			temp = temp->snext;
		new->sprev = temp;
		new->snext = temp->snext;
		if (temp->snext == NULL)
			ht->stail = new;
		else
			temp->snext->sprev = new;
		temp->snext = new;
	}
	return (1);
}

/**
 * shash_table_get - Retrieve the vlaue assoc with a key in the table
 * @ht: Ptr to the table
 * @key: Key to retrieve its value
 * Return: The associate value or NULL if otherwise
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int idx;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);
	idx = key_index((const unsigned char *)key, ht->size);
	if (idx >= ht->size)
		return (NULL);
	node = ht->shead;
	while (node != NULL && strcmp(node->key, key) != 0)
		node = node->snext;
	return ((node == NULL) ? NULL : node->value);
}

/**
 * shash_table_print - Prints the sorted hash table
 * @ht: Ptr to the table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;
	node = ht->shead;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sortd hash table in reverse order
 * @ht: Ptr to the sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;
	node = ht->stail;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Erase a sorted hash table
 * @ht: Ptr to sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *hd = ht;
	shash_node_t *node, *temp;

	if (ht == NULL)
		return;
	node = ht->shead;
	while (node)
	{
		temp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = temp;
	}
	free(hd->array);
	free(hd);
}
