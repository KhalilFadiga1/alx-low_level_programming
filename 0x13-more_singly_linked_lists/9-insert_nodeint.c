#include "lists.h"

/**
 * create_new_node - Create New Element
 * @n: Value of Node
 * Return: New Element
 */
listint_t *create_new_node(int n)
{
	listint_t *new_nd;

	new_nd = malloc(sizeof(listint_t));
	if (new_nd == NULL)
		return (NULL);
	new_nd->n = n;
	new_nd->next = NULL;
	return (new_nd);
}

/**
 * insert_nodeint_at_index - Insert the New Element at specific Posit
 * @head: Ptr to the Node of the list
 * @idx: Posit to Insert New Node
 * @n: Value of the node
 * Return: Ptr to the New Node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{

	listint_t *temp, *temp_old, *new_nd;
	unsigned int x;

	temp = *head;
	if (head == NULL)
		return (NULL);
	new_nd = create_new_node(n);
	if (new_nd == NULL)
		return (NULL);
	if (*head == NULL)
	{
		*head = new_nd;
		return (new_nd);
	}
	if (idx == 0)
		*head = new_nd;
	for (x = 0; x < idx - 1 && temp != NULL && idx != 0; x++)
		temp = temp->next;
	if (temp == NULL)
		return (NULL);
	if (idx == 0)
		new_nd->next = temp;
	else
	{
		temp_old = temp->next;
		temp->next = new_nd;
		new_nd->next = temp_old;
	}
	return (new_nd);
}
