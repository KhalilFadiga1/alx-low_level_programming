#include <stdio.h>
#include "lists.h"

/**
 * listint_len - returns the num of elems in a linked listint_t list
 * @h: Ptr to the head of the listint_len list
 * Return: Total elements in the list
 */
size_t listint_len(const listint_t *h)
{
	size_t nds = 0;

	while (h)
	{
		nds++;
		h = h->next;
	}
	return (nds);
}
