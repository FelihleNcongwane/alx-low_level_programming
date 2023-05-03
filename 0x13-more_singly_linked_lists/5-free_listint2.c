#include "lists.h"

/**
 * free_listint2 - Frees a linked list and sets its head to NULL.
 *
 * @head: Pointer to a pointer to the first node in the list.
 */
void free_listint2(listint_t **head)
{
    listint_t *current_node, *next_node;

    /* If head is NULL or points to NULL, there is nothing to free */
    if (head == NULL || *head == NULL)
        return;

    /* Traverse the list and free each node */
    for (current_node = *head; current_node != NULL; )
    {
        /* Save the next node before freeing the current node */
        next_node = current_node->next;

        /* Free the current node */
        free(current_node);

        /* Update the current node to the next node */
        current_node = next_node;
    }

    /* Set the head pointer to NULL to indicate that the list is empty */
    *head = NULL;
}
