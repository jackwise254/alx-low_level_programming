#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list and returns
 * the head node's data.
 * @head: double pointer to the head of the list
 *
 * Return: head node's data, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
    int data;
    listint_t *tmp;

    if (!head || !*head)
        return (0);

    tmp = *head;
    data = (*head)->n;
    *head = (*head)->next;
    free(tmp);

    return (data);
}

