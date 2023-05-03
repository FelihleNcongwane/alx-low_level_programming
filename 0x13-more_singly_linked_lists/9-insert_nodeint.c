#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node in a linked list, at a given position.
 *
 * @head: Pointer to the first node in the list.
 * @idx: Index where the new node is added.
 * @n: Data to insert in the new node.
 *
 * Return: Pointer to the new node, or NULL if the index is out of range or memory allocation fails.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    unsigned int i;
    listint_t *new_node, *current_node;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL || head == NULL)
    {
        return (NULL);
    }

    /* Initialize the new node */
    new_node->n = n;
    new_node->next = NULL;

    /* Handle the case where we insert at the beginning of the list */
    switch (idx)
    {
        case 0:
            new_node->next = *head;
            *head = new_node;
            return (new_node);
    }

    /* Traverse the list until we reach the desired index */
    i = 0;
    current_node = *head;
    while (current_node != NULL && i < idx - 1)
    {
        current_node = current_node->next;
        i++;
    }

    /* Insert the new node at the desired index */
    switch (current_node != NULL)
    {
        case 1:
            new_node->next = current_node->next;
            current_node->next = new_node;
            return (new_node);
        default:
            free(new_node);
            return (NULL);
    }
}
