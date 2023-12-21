/* 3-hash_table_set.c */
#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_set - Adds an element to the hash table.
 * @ht: The hash table to add or update the key/value to.
 * @key: The key (cannot be an empty string).
 * @value: The value associated with the key (duplicated, can be an empty string).
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    hash_node_t *new_node, *current_node;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0')
        return (0);

    index = key_index((unsigned char *)key, ht->size);
    current_node = ht->array[index];

    /* Check if key already exists, update value if true */
    while (current_node)
    {
        if (strcmp(current_node->key, key) == 0)
        {
            free(current_node->value);
            current_node->value = strdup(value);
            if (current_node->value == NULL)
                return (0);
            return (1);
        }
        current_node = current_node->next;
    }

    /* Create new node for key-value pair */
    new_node = malloc(sizeof(hash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    if (new_node->key == NULL || new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node->value);
        free(new_node);
        return (0);
    }

    /* Add new node at the beginning of the list in case of collision */
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return (1);
}

