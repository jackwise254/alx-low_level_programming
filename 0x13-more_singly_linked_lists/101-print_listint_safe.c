#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the start of the linked list
 * 
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *slow, *fast, *marker;
    size_t nodes = 0;

    if (head == NULL)
        exit(98);

    slow = head;
    fast = head;

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) /* Loop detected */
        {
            marker = head;
            while (1)
            {
                if (marker == slow)
                {
                    printf("-> [%p] %d\n", (void *)marker, marker->n);
                    return (nodes);
                }
                printf("[%p] %d\n", (void *)marker, marker->n);
                marker = marker->next;
                nodes++;
            }
        }
    }

    /* No loop - print normally */
    while (head)
    {
        printf("[%p] %d\n", (void *)head, head->n);
        head = head->next;
        nodes++;
    }

    return (nodes);
}
