#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space
 *           in memory, which contains a copy of the string given.
 * @str: string to duplicate.
 *
 * Return: pointer to the duplicated string, or NULL if insufficient memory
 *         or if str is NULL.
 */
char *_strdup(char *str)
{
    char *dup;
    unsigned int i = 0, len = 0;

    /* Check if str is NULL */
    if (str == NULL)
        return (NULL);

    /* Get the length of the string */
    while (str[len])
        len++;

    /* Allocate memory for the new string */
    dup = (char *)malloc((len + 1) * sizeof(char));

    /* If malloc failed, return NULL */
    if (dup == NULL)
        return (NULL);

    /* Copy the string */
    while (i < len)
    {
        dup[i] = str[i];
        i++;
    }

    /* Null terminate the duplicated string */
    dup[i] = '\0';

    return (dup);
}
