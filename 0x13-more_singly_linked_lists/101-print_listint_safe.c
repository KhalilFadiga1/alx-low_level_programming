#include "lists.h"
#include <stdio.h>

/**
 * free_listp - Delete an element
 * @head: Ptr to Head
 */
void free_listp(listp_t **head)
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
 * print_listint_safe - Displays LIstint_t linked list
 * @head: Ptr to the Head
 * Return: Num of Elem in the List
 */
size_t print_listint_safe(const listint_t *head)
{
	listp_t *nw, *addd, *hptr;
	size_t nds = 0;

	hptr = NULL;
	while (head != NULL)
	{
		nw = malloc(sizeof(listint_t));
		if (nw == NULL)
			exit(98);
		nw->p = (void *)head;
		nw->next = hptr;
		hptr = nw;
		addd = hptr;
		while (addd->next != NULL)
		{
			addd = addd->next;
			if (head == addd->p)
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free_listp(&hptr);
				return (nds);
			}
		}
		printf("[%p] %d\n",  (void *)head, head->n);
		head = head->next;
		nds++;
	}
	free_listp(&hptr);
	return (nds);
}
