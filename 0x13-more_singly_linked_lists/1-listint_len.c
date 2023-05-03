#include "lists.h"

/**
 * listint_len - Returns the number of elements in a linked list.
 *
 * @head: Pointer to the beginning of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t listint_len(const listint_t *head)
{
    size_t node_count = 0;

    for (; head != NULL; head = head->next)
    {
        node_count++;
    }

    return (node_count);
}
