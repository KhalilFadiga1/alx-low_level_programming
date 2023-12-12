#include "lists.h"

/**
 * get_nodeint_at_index - Get nth Node of the list
 * @head: Ptr to first node of the list
 * @index: Nth node Position
 * Return: Ptr to the Nth Node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int x = 0;

	for (; x < index; x++)
	{
		if (head == NULL)
			return (NULL);
		head = head->next;
	}
	return (head);
}
