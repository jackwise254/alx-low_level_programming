#include "lists.h"
#include <stdio.h>

/**
 * print_listint - prints all elements of a listint_t list.
 * @h: pointer to head of the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint(const listint_t *h)
{
    size_t count = 0;

    while (h != NULL)
    {
        printf("%d\n", h->n);
        h = h->next;
        count++;
    }

    return (count);
}

