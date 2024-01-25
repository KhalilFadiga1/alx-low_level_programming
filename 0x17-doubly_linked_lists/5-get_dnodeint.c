#include "lists.h"

/**
 * get_dnodeint_at_index - Retrieve the Nth Node of the list
 * @head: List Head
 * @index: Nth Node of the Index
 * Return: Nth Node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int x = 0;

	if (head == NULL)
		return (NULL);
	while (head->prev != NULL)
		head = head->prev;
	while (head != NULL)
	{
		if (x == index)
			break;
		head = head->next;
		x++;
	}
	return (head);
}
