#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to a pointer to the head of the list
 * @idx: index where the new node should be added
 * @n: value to store in the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new_node, *temp;
    unsigned int i;

    if (!h)
        return (NULL);

    new_node = malloc(sizeof(dlistint_t));
    if (!new_node)
        return (NULL);

    new_node->n = n;

    if (idx == 0)
    {
        new_node->prev = NULL;
        new_node->next = *h;
        if (*h)
            (*h)->prev = new_node;
        *h = new_node;
        return (new_node);
    }

    temp = *h;
    for (i = 0; i < idx - 1 && temp; i++)
        temp = temp->next;

    if (!temp)
    {
        free(new_node);
        return (NULL);
    }

    new_node->prev = temp;
    new_node->next = temp->next;

    if (temp->next)
        temp->next->prev = new_node;

    temp->next = new_node;

    return (new_node);
}

