#include "hash_tables.h"

/**
 * key_index - Locate the index at which a key/value pair
 * shd be stored in a Hash Table Array
 * @key: Element key to determine its index
 * Return: Key Index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
