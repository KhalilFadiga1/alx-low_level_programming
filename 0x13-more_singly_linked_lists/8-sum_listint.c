#include "lists.h"

/**
 * sum_listint - Calculate Total of the value in the list
 * @head: Ptr to the Head of the List
 * Return: Total value of the List
 */
int sum_listint(listint_t *head)
{
	int total = 0;

	while (head != NULL)
	{
		total += head->n;
		head = head->next;
	}
	return (total);
}
