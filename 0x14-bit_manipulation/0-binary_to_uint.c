#include "lists.h"

/**
 * print_listint - prints all the elements of a linked list
 * @head: linked list of type listint_t to print
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *head)
{
	/* Initialize variable to count number of nodes */
	size_t node_count = 0;

	/* Traverse the linked list and print each node */
	for (; head != NULL; head = head->next)
	{
		printf("%d\n", head->n);
		node_count++;
	}

	/* Return the number of nodes in the linked list */
	return (node_count);
}
