#include <stdio.h>
#include "lists.h"

/**
 * print_list - Prints all the elements of a linked list
 * @head: Pointer to the list_t list to print
 *
 * Return: The number of nodes printed
 */

size_t print_list(const list_t *head)
{
    size_t count = 0;

    while (head)
    {
        if (!head->str)
            printf("[0] (nil)\n");
        else
            printf("[%u] %s\n", head->len, head->str);

        head = head->next;
        count++;
    }

    return (count);
}
