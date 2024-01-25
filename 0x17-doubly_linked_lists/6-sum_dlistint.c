#include "lists.h"

/**
 * sum_dlistint - Sum of All values of the List
 * @head: List Head
 * Return: Sum of data
 */
int sum_dlistint(dlistint_t *head)
{
	int number = 0;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;
		while (head != NULL)
		{
			number += head->n;
			head = head->next;
		}
	}
	return (number);
}
