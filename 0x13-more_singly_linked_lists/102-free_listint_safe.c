#include "lists.h"

/**
 * free_listint_safe - safely frees a listint_t list
 * @h: double pointer to the head of the list
 *
 * Return: the size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
    listint_t *tortoise, *hare;
    size_t count = 0;

    if (!h || !*h)
        return (0);

    tortoise = *h;
    hare = *h;

    while (tortoise && hare && hare->next)
    {
        count++;

        tortoise = tortoise->next;
        hare = hare->next->next;

        /* If a cycle is detected, break the loop */
        if (tortoise == hare)
        {
            count++;
            break;
        }
    }

    /* Reset tortoise to the head to calculate the size of the list */
    tortoise = *h;
    while (count--)
    {
        hare = tortoise;
        tortoise = tortoise->next;
        free(hare);
    }

    *h = NULL;

    return (count);
}
