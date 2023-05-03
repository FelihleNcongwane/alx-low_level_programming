#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes a node in a linked list at a certain index.
 *
 * @head: Pointer to the first element in the list.
 * @index: Index of the node to delete.
 *
 * Return: 1 (Success), or -1 (Fail).
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *current_node, *previous_node;
    unsigned int i;

    /* Handle the case where the list is empty */
    switch (head == NULL || *head == NULL)
    {
        case 1:
            return (-1);
    }

    /* Handle the case where we delete the head node */
    switch (index)
    {
        case 0:
            current_node = (*head)->next;
            free(*head);
            *head = current_node;
            return (1);
    }

    /* Traverse the list until we reach the node before the desired index */
    previous_node = *head;
    for (i = 0; i < index - 1; i++)
    {
        current_node = previous_node->next;
        if (current_node == NULL)
        {
            return (-1);
        }
        previous_node = current_node;
    }

    /* Delete the node at the desired index */
    current_node = previous_node->next;
    if (current_node == NULL)
    {
        return (-1);
    }
    previous_node->next = current_node->next;
    free(current_node);

    return (1);
}
