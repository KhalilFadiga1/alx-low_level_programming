#include "lists.h"

/**
 * free_listint - Freeing a Listint_t List Node
 * @head: Ptr to the Head of List to free
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
