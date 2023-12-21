/* 4-hash_table_get.c */
#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - Retrieves a value associated with a key.
 * @ht: The hash table to look into.
 * @key: The key to search for.
 *
 * Return: The value associated with the element, or NULL if key couldn’t be found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    hash_node_t *current_node;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    index = key_index((unsigned char *)key, ht->size);
    current_node = ht->array[index];

    while (current_node)
    {
        if (strcmp(current_node->key, key) == 0)
            return (current_node->value);
        current_node = current_node->next;
    }

    return (NULL);
}

