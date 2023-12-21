/* 2-key_index.c */
#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * key_index - Gets the index of a key in a hash table array.
 * @key: The key to get the index for.
 * @size: The size of the array of the hash table.
 *
 * Return: The index at which the key should be stored in the array.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    if (key == NULL || size == 0)
        return (0);

    return (hash_djb2(key) % size);
}

