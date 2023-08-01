#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list
 * @head: A pointer to the head of th listint_t list
 */
void free_listint2(listint_t **head)
{
	listint_t *tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	head = NULL;
}
