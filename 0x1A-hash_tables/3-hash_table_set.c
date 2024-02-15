#include "hash_tables.h"

/**
 * hash_table_set - Add or update an element in a hash table
 * @ht: Ptr to the Hash_Table
 * @key: new key to add or update
 * @value: assoc value of the key
 * Return: 1 or 0 if fails
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new;
	char *val_cpy;
	unsigned long int idx, x;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	val_cpy = strdup(value);
	if (val_cpy == NULL)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);
	for (x = idx; ht->array[x]; x++)
	{
		if (strcmp(ht->array[x]->key, key) == 0)
		{
			free(ht->array[x]->value);
			ht->array[x]->value = val_cpy;
			return (1);
		}
	}
	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
	{
		free(new);
		return (0);
	}
	new->value = val_cpy;
	new->next = ht->array[idx];
	ht->array[idx] = new;
	return (1);
}
