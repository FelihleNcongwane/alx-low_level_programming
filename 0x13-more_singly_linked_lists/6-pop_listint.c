#include "lists.h"

/**
 * pop_listint - Deletes the head node of a linked list.
 *
 * @head: Pointer to the first element in the linked list.
 *
 * Return: The data inside the element that was deleted, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
    listint_t *next_node;
    int deleted_data;

    switch (head == NULL || *head == NULL)
    {
        case 1:
            return (0);
        default:
            deleted_data = (*head)->n;
            next_node = (*head)->next;
            free(*head);
            *head = next_node;
            return (deleted_data);
    }
}
