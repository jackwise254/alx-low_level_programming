#include "lists.h"
#include <stdio.h>

/**
 * is_node_visited - checks if a node has been visited before.
 * @addr: address of node to check
 * @visited_nodes: array of addresses to check against
 * @index: number of nodes visited so far
 *
 * Return: 1 if node has been visited, 0 otherwise
 */
int is_node_visited(const listint_t *addr, const listint_t *visited_nodes[], size_t index)
{
    size_t i;
    for (i = 0; i < index; i++)
    {
        if (visited_nodes[i] == addr)
            return (1);
    }
    return (0);
}

/**
 * print_listint_safe - prints a listint_t linked list safely.
 * @head: pointer to the head of the list
 *
 * Return: number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t count = 0;
    const listint_t *visited_nodes[1024];

    while (head)
    {
        printf("[%p] %d\n", (void *)head, head->n);
        visited_nodes[count] = head;
        count++;

        if (is_node_visited(head->next, visited_nodes, count))
        {
            printf("-> [%p] %d\n", (void *)head->next, head->next->n);
            break;
        }

        head = head->next;
    }

    return (count);
}

