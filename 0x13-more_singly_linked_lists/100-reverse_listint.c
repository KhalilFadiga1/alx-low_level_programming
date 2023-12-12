#include "lists.h"

/**
 * reverse_listint - Move Backwards
 * @head: Ptr to Head of the List
 * Return: Ptr to the Beginning of the List
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *new_temp, *temp;

	if (*head == NULL || head == NULL)
		return (NULL);
	temp = *head;
	*head = temp->next;
	temp->next = NULL;
	while (*head != NULL)
	{
		new_temp = (*head)->next;
		(*head)->next = temp;
		temp = *head;
		if (new_temp == NULL)
			return (*head);
		*head = new_temp;
	}
	if (*head == NULL)
	{
		*head = temp;
		return (*head);
	}
	return (NULL);
}
