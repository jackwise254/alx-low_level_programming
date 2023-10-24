#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - prints a listint_t linked list safely.
 * @head: pointer to the head of the list
 *
 * Return: number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *slow = head, *fast = head;
    size_t count = 0;
    int loop_detected = 0;

    while (head && (!loop_detected || head != slow))
    {
        printf("[%p] %d\n", (void *)head, head->n);
        count++;
        head = head->next;

        if (loop_detected && head == slow)
        {
            printf("-> [%p] %d\n", (void *)head, head->n);
            break;
        }

        if (!loop_detected && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                loop_detected = 1;
                slow = head;
            }
        }
    }

    if (!loop_detected && fast && !fast->next)
        return (count);

    return (count);
}

