#include "lists.h"

/**
 * sum_listint - Calculates the sum of all the data in a listint_t list.
 *
 * @head: Pointer to the first node in the linked list.
 *
 * Return: The resulting sum.
 */
int sum_listint(listint_t *head)
{
    int sum = 0;
    listint_t *current_node;

    /* Traverse the list and add the data at each node to the sum */
    for (current_node = head; current_node != NULL; current_node = current_node->next)
    {
        sum += current_node->n;
    }

    return (sum);
}
