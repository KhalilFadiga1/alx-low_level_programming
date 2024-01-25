#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a New Node @ a given Posit
 * @h: Head of the List
 * @idx: Posit to insert the New elem
 * @n: Value of the New Node
 * Return: Addr of the New Node or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *nw, *hd;
	unsigned int x;

	nw = NULL;
	if (idx == 0)
		nw = add_dnodeint(h, n);
	else
	{
		hd = *h;
		x = 1;
		if (hd != NULL)
			while (hd->prev != NULL)
				hd = hd->prev;
		while (hd != NULL)
		{
			if (x == idx)
			{
				if (hd->next == NULL)
					nw = add_dnodeint_end(h, n);
				else
				{
					nw = malloc(sizeof(dlistint_t));
					if (nw != NULL)
					{
						nw->n = n;
						nw->next = hd->next;
						nw->prev = hd;
						hd->next->prev = nw;
						hd->next = nw;
					}
				}
				break;
			}
			hd = hd->next;
			x++;
		}
	}
	return (nw);
}
