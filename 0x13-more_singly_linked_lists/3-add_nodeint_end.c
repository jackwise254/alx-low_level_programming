#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list.
 * @head: Double pointer to the head of the list.
 * @n: The integer to store in the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *new_node;
    listint_t *temp;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(listint_t));
    if (!new_node)
        return (NULL);

    /* Initialize new node's data and next pointer */
    new_node->n = n;
    new_node->next = NULL;

    /* If list is empty, make new node the head */
    if (*head == NULL)
    {
        *head = new_node;
        return (new_node);
    }

    /* Traverse to the last node of the list */
    temp = *head;
    while (temp->next)
    {
        temp = temp->next;
    }

    /* Add the new node at the end */
    temp->next = new_node;

    return (new_node);
}

