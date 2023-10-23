#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: Double pointer to the head node of the linked list.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
    listint_t *prev = NULL;
    listint_t *next = NULL;

    while (*head)
    {
        next = (*head)->next;   /* store next */
        (*head)->next = prev;   /* reverse current node's pointer */
        prev = *head;           /* move pointers one position ahead */
        *head = next;
    }
    *head = prev;

    return (*head);
}
