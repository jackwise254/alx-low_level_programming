/* 100-sorted_hash_table.c */
#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the newly created hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht;
    unsigned long int i;

    ht = malloc(sizeof(shash_table_t));
    if (ht == NULL)
        return (NULL);

    ht->size = size;
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (ht->array == NULL)
    {
        free(ht);
        return (NULL);
    }

    for (i = 0; i < size; i++)
        ht->array[i] = NULL;

    ht->shead = NULL;
    ht->stail = NULL;

    return (ht);
}

/**
 * shash_table_set - Adds an element to the sorted hash table.
 * @ht: The sorted hash table.
 * @key: The key.
 * @value: The value associated with the key.
 *
 * Return: 1 if successful, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    shash_node_t *new_node, *prev, *current;
    unsigned long int index;

    if (ht == NULL || key == NULL || value == NULL)
        return (0);

    index = key_index((const unsigned char *)key, ht->size);

    current = ht->shead;
    prev = NULL;

    while (current != NULL && strcmp(current->key, key) < 0)
    {
        prev = current;
        current = current->snext;
    }

    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        free(new_node);
        return (0);
    }

    new_node->value = strdup(value);
    if (new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node);
        return (0);
    }

    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    if (prev == NULL)
    {
        new_node->snext = ht->shead;
        ht->shead = new_node;
    }
    else
    {
        new_node->snext = prev->snext;
        prev->snext = new_node;
    }

    if (new_node->snext == NULL)
        ht->stail = new_node;

    return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key.
 * @ht: The sorted hash table.
 * @key: The key to look for.
 *
 * Return: The value associated with the key, or NULL if key couldn’t be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    shash_node_t *node;
    unsigned long int index;

    if (ht == NULL || key == NULL)
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);

    node = ht->array[index];

    while (node != NULL)
    {
        if (strcmp(node->key, key) == 0)
            return (node->value);
        node = node->next;
    }

    return (NULL);
}

/**
 * shash_table_print - Prints the hash table using the sorted linked list.
 * @ht: The sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *node;

    if (ht == NULL)
        return;

    node = ht->shead;

    printf("{");

    while (node != NULL)
    {
        printf("'%s': '%s'", node->key, node->value);
        if (node->snext != NULL)
            printf(", ");
        node = node->snext;
    }

    printf("}\n");
}

/**
 * shash_table_print_rev - Prints the hash table in reverse order using the sorted linked list.
 * @ht: The sorted hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *node;

    if (ht == NULL)
        return;

    node = ht->stail;

    printf("{");

    while (node != NULL)
    {
        printf("'%s': '%s'", node->key, node->value);
        if (node->sprev != NULL)
            printf(", ");
        node = node->sprev;
    }

    printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: The sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
    shash_node_t *node, *temp;
    unsigned long int i;

    if (ht == NULL)
        return;

    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node != NULL)
        {
            temp = node->next;
            free(node->key);
            free(node->value);
            free(node);
            node = temp;
        }
    }

    free(ht->array);
    free(ht);
}

