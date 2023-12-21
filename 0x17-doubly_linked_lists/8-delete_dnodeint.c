#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index index of a dlistint_t list
 * @head: pointer to a pointer to the head of the list
 * @index: index of the node to delete
 *
 * Return: 1 if succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current, *temp;
    unsigned int i;

    if (!head || !*head)
        return (-1);

    current = *head;

    if (index == 0)
    {
        *head = current->next;
        if (*head)
            (*head)->prev = NULL;
        free(current);
        return (1);
    }

    for (i = 0; i < index && current; i++)
        current = current->next;

    if (!current)
        return (-1);

    if (current->next)
        current->next->prev = current->prev;

    current->prev->next = current->next;

    free(current);

    return (1);
}
