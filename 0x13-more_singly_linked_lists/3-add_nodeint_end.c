#include "lists.h"

/**
 * add_nodeint_end - Add a new node at the end of a listint_t list
 * @head: Pointer to an address of a head of the listint_t list
 * @n: Integer to be contained in a new node
 * Return: An address of the new node; Otherwise, NULL
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new, *last;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	return (*head);
}
