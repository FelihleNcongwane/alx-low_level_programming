#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a linked list
 * @head: pointer to the first node in the list
 * @n: data to insert in that new node
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	/* Allocate memory for new node */
	listint_t *new_node = malloc(sizeof(listint_t));

	/* Check if memory allocation was successful */
	if (!new_node)
		return (NULL);

	/* Initialize new node data and link to existing list */
	new_node->n = n;
	switch (*head)
	{
		case NULL:
			new_node->next = NULL;
			break;
		default:
			new_node->next = *head;
			break;
	}

	/* Update the head pointer to point to the new node */
	*head = new_node;

	/* Return a pointer to the newly added node */
	return (new_node);
}
