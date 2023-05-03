#include "lists.h"

/**
 * get_nodeint_at_index - Returns the node at a certain index in a linked list.
 *
 * @head: Pointer to the first node in the linked list.
 * @index: Index of the node to return.
 *
 * Return: Pointer to the node we're looking for, or NULL if the index is out of range.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
    unsigned int i;
    listint_t *current_node = head;

    /* Traverse the list until we reach the desired index */
    for (i = 0; current_node != NULL && i < index; i++)
    {
        current_node = current_node->next;
    }

    /* Return the node at the desired index, or NULL if the index is out of range */
    return (i == index && current_node != NULL ? current_node : NULL);
}
