#include "lists.h"

/**
 * add_dnodeint_end - Appends a New Elem to the end of the list
 * @head: List Head
 * @n: Node Integer
 * Return: Addr of New Node
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *nw, *hd;

	nw = malloc(sizeof(dlistint_t));
	if (nw == NULL)
		return (NULL);
	nw->n = n;
	nw->next = NULL;
	hd = *head;
	if (hd != NULL)
	{
		while (hd->next != NULL)
			hd = hd->next;
		hd->next = nw;
	}
	else
		*head = nw;
	nw->prev = hd;
	return (nw);
}
