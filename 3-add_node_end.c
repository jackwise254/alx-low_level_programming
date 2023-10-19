#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * _strlen - Length of a string.
 * @s: String.
 *
 * Return: Length of @s.
 */
size_t _strlen(const char *s)
{
    size_t len = 0;

    while (*s++)
        len++;

    return len;
}

/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: Double pointer to the head of the list.
 * @str: String to be included in the new node.
 *
 * Return: Address of the new element, or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
    list_t *new_node;
    list_t *last_node = *head;

    if (!str)
        return (NULL);

    new_node = malloc(sizeof(list_t));
    if (!new_node)
        return (NULL);

    new_node->str = strdup(str);
    if (!(new_node->str))
    {
        free(new_node);
        return (NULL);
    }

    new_node->len = _strlen(new_node->str);
    new_node->next = NULL;

    if (!(*head))
    {
        *head = new_node;
        return (new_node);
    }

    while (last_node->next)
        last_node = last_node->next;

    last_node->next = new_node;

    return (new_node);
}

