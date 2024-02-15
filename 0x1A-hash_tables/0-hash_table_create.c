#include "hash_tables.h"

/**
 * hash_table_create - Make a Hash Table
 * @size: Arr size
 * Return: Ptr to the Hash_Table or NULL if otherwise
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int idx;
	hash_table_t *hsh_t;

	hsh_t = malloc(sizeof(hash_table_t));
	if (hsh_t == NULL)
		return (NULL);
	hsh_t->size = size;
	hsh_t->array = malloc(sizeof(hash_node_t *) * size);
	if (hsh_t->array == NULL)
		return (NULL);
	for (idx = 0; idx < size; idx++)
		hsh_t->array[idx] = NULL;
	return (hsh_t);
}
