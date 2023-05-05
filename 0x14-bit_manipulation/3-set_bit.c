#include "lists.h"

/**
 * add_nodeint_end - adds a node at the end of a linked list
 * @head: pointer to the first element in the list
 * @n: data to insert in the new element
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	/* Allocate memory for new node */
	listint_t *new_node = malloc(sizeof(listint_t));

	/* Check if memory allocation was successful */
	if (!new_node)
		return (NULL);

	/* Initialize new node data and link to existing list */
	new_node->n = n;
	new_node->next = NULL;

	switch (*head)
	{
		case NULL:
			*head = new_node;
			break;
		default:
			/* Traverse the list to the end and add the new node */
			listint_t *temp;
			for (temp = *head; temp->next != NULL; temp = temp->next)
				continue;
			temp->next = new_node;
			break;
	}

	/* Return a pointer to the newly added node */
	return (new_node);
}
