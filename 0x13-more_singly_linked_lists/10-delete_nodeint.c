#include "lists.h"

/**
 * delete_nodeint_at_index - Remove a Specific Elem from the List
 * @head: Ptr to the Head of the List
 * @index: Posit of Elem to delete
 * Return: if worked, 1 or -1 for failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *nd;
	unsigned int x;

	temp = *head;
	if (*head == NULL || head == NULL)
		return (-1);
	for (x = 0; x < index - 1 && index != 0 && temp != NULL; x++)
		temp = temp->next;
	if (temp == NULL)
		return (-1);
	if (index == 0)
	{
		nd = temp->next;
		free(temp);
		*head = nd;
	}
	else
	{
		if (temp->next == NULL)
			nd = temp->next;
		else
			nd = temp->next->next;
		free(temp->next);
		temp->next = nd;
	}
	return (1);
}
