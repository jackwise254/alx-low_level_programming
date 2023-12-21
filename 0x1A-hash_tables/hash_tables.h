#ifndef HASH_TABLES_H
#define HASH_TABLES_H

/* Node structure for hash table */
typedef struct hash_node
{
    char *key;
    char *value;
    struct hash_node *next;
} hash_node_t;

/* Hash table structure */
typedef struct hash_table
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;

/* Function prototypes */
hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
void hash_table_delete(hash_table_t *ht);
void hash_table_print(const hash_table_t *ht);
char *hash_table_get(const hash_table_t *ht, const char *key);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
unsigned long int key_index(const unsigned char *key, unsigned long int size);

#endif /* HASH_TABLES_H */

