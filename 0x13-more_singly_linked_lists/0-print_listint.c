#include "lists.h"

/**
 * print_listint - Prints all the elements of a linked list.
 *
 * @head: Pointer to the beginning of the list.
 *
 * Return: The number of nodes in the list.
 */

size_t print_listint(const listint_t *head)
{
    size_t node_count = 0;

    while (head != NULL)
    {
        printf("%d\n", head->n);
        node_count++;
        head = head->next;
    }

    return (node_count);
}
