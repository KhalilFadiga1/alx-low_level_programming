#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a linked list
 * @head: A pointer to the head of a linked list
 * @index: Index of the node, starting at 0
 * Return: pointer to the node being searched or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *tempt = head;

	while (tempt && i < index)
	{
		tempt = tempt->next;
		i++;
	}
	return (tempt ? tempt : NULL);
}
