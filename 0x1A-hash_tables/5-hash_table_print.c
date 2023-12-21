#include "hash_tables.h"

/**
 * hash_table_print - Print a hash table.
 * @ht: The hash table to print.
 */
void hash_table_print(const hash_table_t *ht)
{
    unsigned long int i;
    hash_node_t *current;
    int first = 1; /* Flag to print ',' and space */

    if (ht == NULL)
        return;

    printf("{");
    for (i = 0; i < ht->size; i++)
    {
        current = ht->array[i];
        while (current)
        {
            /* Print ',' and space if not the first pair */
            if (!first)
                printf(", ");
            printf("'%s': '%s'", current->key, current->value);
            first = 0;
            current = current->next;
        }
    }
    printf("}\n");
}

