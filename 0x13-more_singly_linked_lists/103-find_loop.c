#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: pointer to the head of the list
 *
 * Return: address of the node where the loop starts, or NULL if no loop exists
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *tortoise, *hare;

    if (!head)
        return (NULL);

    tortoise = hare = head;

    /* Phase 1: Check if there's a loop using Floyd's cycle-finding algorithm */
    while (hare && hare->next)
    {
        tortoise = tortoise->next;
        hare = hare->next->next;

        if (tortoise == hare)
            break;
    }

    /* If no loop was found, return NULL */
    if (tortoise != hare)
        return (NULL);

    /* Phase 2: Find the start of the loop */
    tortoise = head;
    while (tortoise != hare)
    {
        tortoise = tortoise->next;
        hare = hare->next;
    }

    return (tortoise);
}
