#include "lists.h"

/**
 * pop_listint - deletes the head node of a linked list
 * @head: pointer to the first element in the linked list
 *
 * Return: the data inside the element that was deleted,
 * or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	/* Check if head pointer or list is empty */
	switch (head == NULL || *head == NULL)
	{
		case true:
			return (0);
		default:
			break;
	}

	/* Store the data of the head node and free it */
	int num = (*head)->n;
	listint_t *temp = (*head)->next;
	free(*head);

	/* Update the head pointer to point to the next node */
	*head = temp;

	/* Return the data of the deleted node */
	return (num);
}
