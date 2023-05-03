#include "lists.h"

/**
 * free_listint - Frees a linked list.
 *
 * @head: Pointer to the first node in the list.
 */
void free_listint(listint_t *head)
{
    listint_t *current;

    for (current = head; current != NULL; )
    {
        listint_t *temp = current;
        current = current->next;
        free(temp);
    }
}
