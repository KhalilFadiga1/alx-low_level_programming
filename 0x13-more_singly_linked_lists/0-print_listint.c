#include "lists.h"
#include <stdio.h>

/**
 * print_listint - Prints All Elements of Listint_t list
 * @h: Ptr to Head of the Listint_t list
 * Return: Total figure of the nodes in the listint_t list
 */
size_t print_listint(const listint_t *h)
{
	size_t nds = 0;

	while (h)
	{
		nds++;
		printf("%d\n", h->n);
		h = h->next;
	}
	return (nds);
}
