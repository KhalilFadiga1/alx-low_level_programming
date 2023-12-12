#include "lists.h"
#include <stdio.h>

/**
 * free_listp2 - Delete an element
 * @head: Ptr to Head
 */
void free_listp2(listp_t **head)
{
	listp_t *cur, *temp;

	if (head != NULL)
	{
		cur = *head;
		while ((temp = cur) != NULL)
		{
			cur = cur->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * free_listint_safe - Displays LIstint_t linked list
 * @h: Ptr to the Head
 * Return: Num of Elem in the List
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *cur;
	listp_t *nw, *addd, *hptr;
	size_t nds = 0;

	hptr = NULL;
	while (*h != NULL)
	{
		nw = malloc(sizeof(listint_t));
		if (nw == NULL)
			exit(98);
		nw->p = (void *)*h;
		nw->next = hptr;
		hptr = nw;
		addd = hptr;
		while (addd->next != NULL)
		{
			addd = addd->next;
			if (*h == addd->p)
			{
				*h = NULL;
				free_listp2(&hptr);
				return (nds);
			}
		}
		cur = *h;
		*h = (*h)->next;
		free(cur);
		nds++;
	}
	*h = NULL;
	free_listp2(&hptr);
	return (nds);
}
