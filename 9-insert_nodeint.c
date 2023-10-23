#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: double pointer to the head of the list
 * @idx: the index where the new node should be added, starts at 0
 * @n: data for the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    unsigned int i = 0;
    listint_t *new, *temp = *head;

    /* Allocate new node */
    new = malloc(sizeof(listint_t));
    if (!new)
        return (NULL);

    new->n = n;
    new->next = NULL;

    /* if the linked list is empty or idx is 0 */
    if (!*head || idx == 0)
    {
        new->next = *head;
        *head = new;
        return (new);
    }

    /* Traverse the linked list up to the position before idx */
    while (temp && i < idx - 1)
    {
        temp = temp->next;
        i++;
    }

    /* if we reached the end or idx doesn't exist, return NULL */
    if (!temp)
    {
        free(new);
        return (NULL);
    }

    new->next = temp->next;
    temp->next = new;

    return (new);
}
