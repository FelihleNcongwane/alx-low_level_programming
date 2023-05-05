#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked list
 * @head: linked list of type listint_t to traverse
 *
 * Return: number of nodes
 */
size_t listint_len(const listint_t *head)
{
	/* Initialize variable to count number of nodes */
	size_t node_count = 0;

	/* Traverse the linked list and count each node */
	for (; head != NULL; head = head->next)
	{
		node_count++;
	}

	/* Return the number of nodes in the linked list */
	return (node_count);
}
