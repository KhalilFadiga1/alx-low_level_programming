#include "lists.h"

/**
 * delete_dnodeint_at_index - Delete the Node at a specific posit
 * in the linked list
 * @head: List Head
 * @index: New Element Index
 * Return: 1 if Successful  and -1 if not
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int x;
	dlistint_t *hd1, *hd2;

	hd1 = *head;
	if (hd1 != NULL)
		while (hd1->prev != NULL)
			hd1 = hd1->prev;
	x = 0;
	while (hd1 != NULL)
	{
		if (x == index)
		{
			if (x == 0)
			{
				*head = hd1->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				hd2->next = hd1->next;
				if (hd1->next != NULL)
					hd1->next->prev = hd2;
			}
			free(hd1);
			return (1);
		}
		hd2 = hd1;
		hd1 = hd1->next;
		x++;
	}
	return (-1);
}
