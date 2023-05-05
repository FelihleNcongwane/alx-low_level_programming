#include "lists.h"

/**
 * free_listint - frees a linked list
 * @head: listint_t list to be freed
 */
void free_listint(listint_t *head)
{
	/* Traverse the linked list and free each node */
	for (; head != NULL;)
	{
		listint_t *temp = head->next;
		free(head);
		head = temp;
	}
}
