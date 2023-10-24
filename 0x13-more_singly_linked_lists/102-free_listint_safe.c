#include "lists.h"

/**
 * find_loop - find the node where the loop starts
 * using Floyd's Cycle-Finding Algorithm.
 * @head: pointer to the head of the list
 *
 * Return: address of the node where loop starts, or NULL if there is no loop
 */
listint_t *find_loop(listint_t *head)
{
    listint_t *tortoise = head;
    listint_t *hare = head;

    while (tortoise && hare && hare->next)
    {
        tortoise = tortoise->next;
        hare = hare->next->next;
        if (tortoise == hare)
        {
            tortoise = head;
            while (tortoise != hare)
            {
                tortoise = tortoise->next;
                hare = hare->next;
            }
            return hare;
        }
    }

    return NULL;
}

/**
 * free_listint_safe - frees a listint_t linked list safely.
 * @h: double pointer to the head of the list
 *
 * Return: size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
    size_t count = 0;
    listint_t *tmp, *loop_start;

    if (!h || !(*h))
        return 0;

    loop_start = find_loop(*h);

    while (*h)
    {
        if (*h == loop_start && count > 0)
            break;

        tmp = *h;
        *h = (*h)->next;
        free(tmp);
        count++;

        if (*h && !(*h)->next && *h == loop_start) 
        {
            free(*h);
            *h = NULL;
            count++;
        }
    }

    *h = NULL;
    return count;
}

