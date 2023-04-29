#include <stdlib.h>
#include "lists.h"

/**
 * list_len - Returning element number in a linked list
 * @h: Pointer to the list_t list to count
 *
 * Return: The number of nodes in the list
 */

size_t list_len(const list_t *h)
{
    size_t count = 0;

    while (h)
    {
        count++;
        h = h->next;
    }

    return (count);
}
