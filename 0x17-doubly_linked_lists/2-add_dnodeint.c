#include "lists.h"

/**
 * add_dnodeint - append a new element to the beginning
 * of a linked list
 * @head: Head of the List
 * @n: Node value
 * Return: addr of the new node
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *nw, *hd;

	nw = malloc(sizeof(dlistint_t));
	if (nw == NULL)
		return (NULL);
	nw->n = n;
	nw->prev = NULL;
	hd = *head;
	if (hd != NULL)
	{
		while (hd->prev != NULL)
			hd = hd->prev;
	}
	nw->next = hd;
	if (hd != NULL)
		hd->prev = nw;
	*hd = nw;
	return (nw);
}
