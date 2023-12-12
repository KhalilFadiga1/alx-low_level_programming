#include "lists.h"

/**
 * pop_listint - Remove the biginning element of List
 * @head: Ptr to the Head of the List
 * Return: Removed elements' value
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n;

	if (head == NULL || (*head) == NULL)
		return (0);
	n = (*head)->n;
	temp = *head;
	*head = (*head)->next;
	free(temp);
	return (n);
}
