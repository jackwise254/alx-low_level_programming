#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings.
 * @s1: first string.
 * @s2: second string.
 *
 * Return: pointer to the newly concatenated string, or NULL if failure.
 */
char *str_concat(char *s1, char *s2)
{
    unsigned int len1 = 0, len2 = 0, i, j;
    char *new_str;

    /* Handle NULL as empty strings */
    if (!s1)
        s1 = "";
    if (!s2)
        s2 = "";

    /* Calculate length of s1 and s2 */
    while (s1[len1])
        len1++;
    while (s2[len2])
        len2++;

    /* Allocate memory for concatenated string */
    new_str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    if (!new_str)
        return (NULL);

    /* Copy s1 to new_str */
    for (i = 0; i < len1; i++)
        new_str[i] = s1[i];

    /* Copy s2 to new_str after s1 */
    for (j = 0; j < len2; j++, i++)
        new_str[i] = s2[j];

    /* Null terminate the new string */
    new_str[i] = '\0';

    return (new_str);
}
