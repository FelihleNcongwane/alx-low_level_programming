#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - Counts the number of unique nodes
 * in a looped listint_t linked list.
 *
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
    const listint_t *tortoise, *hare;
    size_t nodes = 1;

    /* Handle the case where the list is empty or has only one node */
    switch (head == NULL || head->next == NULL)
    {
        case 1:
            return (0);
    }

    /* Find the loop in the list */
    tortoise = head->next;
    hare = (head->next)->next;
    for (; hare != NULL; hare = hare->next)
    {
        if (tortoise == hare)
        {
            /* Count the number of unique nodes in the list */
            tortoise = head;
            for (; tortoise != hare; nodes++)
            {
                tortoise = tortoise->next;
                hare = hare->next;
            }
            tortoise = tortoise->next;
            for (; tortoise != hare; nodes++)
            {
                tortoise = tortoise->next;
            }
            return (nodes);
        }
        tortoise = tortoise->next;
        hare = (hare->next == NULL) ? NULL : hare->next->next;
    }

    return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 *
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t nodes, index = 0;

    nodes = looped_listint_len(head);

    /* Handle the case where the list is not looped */
    switch (nodes == 0)
    {
        case 1:
            for (; head != NULL; nodes++)
            {
                printf("[%p] %d\n", (void *)head, head->n);
                head = head->next;
            }
            break;
    }

    /* Handle the case where the list is looped */
    switch (nodes != 0)
    {
        case 1:
            for (index = 0; index < nodes; index++)
            {
                printf("[%p] %d\n", (void *)head, head->n);
                head = head->next;
            }
            printf("-> [%p] %d\n", (void *)head, head->n);
            break;
    }

    return (nodes);
}
