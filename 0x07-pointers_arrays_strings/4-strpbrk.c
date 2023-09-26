#include "main.h"

/**
 * _strpbrk - Searches a string for any of a set of bytes.
 * @s: The string to be scanned.
 * @accept: The string containing the bytes to match.
 *
 * Return: A pointer to the byte in s that matches one of the bytes in accept,
 *         or NULL if no such byte is found.
 */
char *_strpbrk(char *s, char *accept)
{
    while (*s)
    {
        char *temp = accept;

        while (*temp)
        {
            if (*s == *temp)
            {
                return s;
            }
            temp++;
        }

        s++;
    }

    return NULL;
}
