#include "lists.h"

/**
 * dlistint_len - Number of Elms in the Linked List
 * @h: First Node of the List (Head)
 * Return: Number of Elms of the List
 */
size_t dlistint_len(const dlistint_t *h)
{
	int res = 0;

	if (h == NULL)
		return (res);
	while (h->prev != NULL)
		h = h->prev;
	while (h != NULL)
	{
		res++;
		h = h->next;
	}
	return (res);
}
