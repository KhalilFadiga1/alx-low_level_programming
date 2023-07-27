#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * list_len - Determine the number of element in a list
 * @h: The linked list
 * Return: The number of element in the list
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		h = h->next;
		count++;
	}
	return (count);
}
