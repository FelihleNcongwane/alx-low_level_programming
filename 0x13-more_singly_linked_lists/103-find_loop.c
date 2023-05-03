#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 *
 * @head: linked list to search for
 *
 * Return: address of the node where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *slow = head, *fast = head;

    /* Handle the case where the list is empty */
    switch (head == NULL)
    {
        case 1:
            return (NULL);
    }

    /* Find the loop in the list */
    for (; slow && fast && fast->next;)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            for (; slow != fast;)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return (fast);
        }
    }

    return (NULL);
}
