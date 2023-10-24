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
 * free_listint_safe - frees a listint_t linked list safely.
 * @h: double pointer to the head of the list
 *
 * Return: size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
    size_t count = 0;
    listint_t *tmp;
    const listint_t *visited_nodes[1024];

    while (*h && !is_node_visited(*h, visited_nodes, count))
    {
        visited_nodes[count] = *h;
        tmp = *h;
        *h = (*h)->next;
        free(tmp);
        count++;
    }

    *h = NULL;  // Set the head to NULL after freeing

    return (count);
}

