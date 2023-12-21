/* hash_tables.h */
#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>

/* Data structure for a hash table node */
typedef struct hash_node {
    char *key;
    char *value;
    struct hash_node *next;
} hash_node_t;

/* Data structure for a hash table */
typedef struct hash_table {
    size_t size;
    hash_node_t **array;
} hash_table_t;

/* Function prototypes */
hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);

#endif /* HASH_TABLES_H */

/* hash_table_create.c */
#include "hash_tables.h"

/* Creates a hash table */
hash_table_t *hash_table_create(unsigned long int size) {
    hash_table_t *hash_table;
    size_t i;

    /* Allocate memory for the hash table structure */
    hash_table = malloc(sizeof(hash_table_t));
    if (hash_table == NULL)
        return (NULL);

    /* Allocate memory for the array of hash_node_t pointers */
    hash_table->array = malloc(sizeof(hash_node_t *) * size);
    if (hash_table->array == NULL) {
        free(hash_table);
        return (NULL);
    }

    /* Initialize each element of the array to NULL */
    for (i = 0; i < size; ++i)
        hash_table->array[i] = NULL;

    /* Set the size of the hash table */
    hash_table->size = size;

    return (hash_table);
}

/* 1-djb2.c */
unsigned long int hash_djb2(const unsigned char *str) {
    unsigned long int hash;
    int c;

    hash = 5381;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return (hash);
}

/* 1-main.c */
#include <stdio.h>
#include "hash_tables.h"

int main(void) {
    hash_table_t *ht;
    char *s;

    /* Create a hash table with size 1024 */
    ht = hash_table_create(1024);
    if (ht == NULL) {
        fprintf(stderr, "Failed to create hash table\n");
        return (EXIT_FAILURE);
    }

    /* Test the hash_djb2 function */
    s = "cisfun";
    printf("%s: %lu\n", s, hash_djb2((unsigned char *)s));

    s = "Don't forget to tweet today";
    printf("%s: %lu\n", s, hash_djb2((unsigned char *)s));

    s = "98";
    printf("%s: %lu\n", s, hash_djb2((unsigned char *)s));

    return (EXIT_SUCCESS);
}

