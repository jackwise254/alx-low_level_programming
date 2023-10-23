#include "lists.h"

/**
 * delete_nodeint_at_index - deletes node at index of a listint_t linked list
 * @head: double pointer to the head of the list
 * @index: the index of the node that should be deleted, starts at 0
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *temp = *head, *prev;
    unsigned int i = 0;

    if (!head || !(*head))
        return (-1);

    /* Delete first node */
    if (index == 0)
    {
        *head = temp->next;
        free(temp);
        return (1);
    }

    /* Traverse list up to the node just before the index */
    while (temp && i < index)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }

    /* If position is more than the number of nodes */
    if (!temp || i != index)
        return (-1);

    /* Node temp is skipped */
    prev->next = temp->next;
    free(temp);

    return (1);
}
