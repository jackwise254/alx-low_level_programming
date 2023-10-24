#include "lists.h"

/**
 * free_listint2 - frees a listint_t list and sets the head to NULL
 * @head: double pointer to the head of the list
 */
void free_listint2(listint_t **head)
{
    listint_t *tmp;

    if (!head)
        return;

    while (*head)
    {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }

    *head = NULL;
}

