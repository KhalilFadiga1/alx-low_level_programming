#include "lists.h"

/**
 * add_nodeint_end - Addition of New Node at the end of List
 * @head: Ptr to the Head of the List
 * @n: Node's value
 * Return: Ptr to the New Node or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *last, *new;

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
