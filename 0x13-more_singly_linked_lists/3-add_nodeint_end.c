#include "lists.h"

/**
 * add_nodeint_end - Adds a node at the end of a linked list.
 *
 * @head: Pointer to the first element in the list.
 * @n: Data to insert in the new element.
 *
 * Return: Pointer to the new node, or NULL if it fails.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *new_node = malloc(sizeof(listint_t));

    if (new_node == NULL)
    {
        return (NULL);
    }

    new_node->n = n;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return (new_node);
    }
    else if ((*head)->next == NULL)
    {
        (*head)->next = new_node;
        return (new_node);
    }
    else
    {
        listint_t *temp;

        for (temp = *head; temp->next != NULL; temp = temp->next)
        {
            ;
        }

        temp->next = new_node;
        return (new_node);
    }
}
