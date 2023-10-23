#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list and returns
 * the head node's data (n)
 * @head: double pointer to the head of the list
 *
 * Return: head node's data or 0 if linked list is empty
 */
int pop_listint(listint_t **head)
{
    int n;
    listint_t *temp;

    if (!(*head)) /* if list is empty */
        return (0);

    temp = *head;
    n = temp->n;

    *head = (*head)->next;
    free(temp);

    return (n);
}
