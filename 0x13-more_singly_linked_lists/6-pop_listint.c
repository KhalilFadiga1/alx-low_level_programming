#include "lists.h"

/**
 * pop_listint - Delete the head node of listint_t linked list
 * @head: The pointer to the address of head of the listint_t list
 * Return: The head of node data(n)
 */
int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int num;

	if (!head || !*head)
		return (0);
	num = (*head)->n;
	tmp = (*head)->next;
	free(*head);
	*head = tmp;
	return (num);
}
