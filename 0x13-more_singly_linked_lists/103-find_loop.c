#include "lists.h"

/**
 * find_listint_loop - Detects the number of loops in the list
 * @head: Ptr to the Head
 * Return: Ptr to the Beginning of the Loop's Element
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *previous, *p;

	previous = head;
	p = head;
	while (p && p->next && head)
	{
		head = head->next;
		p = p->next->next;
		if (
