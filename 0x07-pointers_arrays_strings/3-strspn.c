#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring.
 * @s: The string to be scanned.
 * @accept: The string containing the characters to match.
 *
 * Return: The number of bytes in the initial segment
 *         of s which consist only of bytes from accept.
 */
unsigned int _strspn(char *s, char *accept)
{
    unsigned int count = 0;
    char *orig_accept = accept;

    while (*s && *accept)
    {
        for (accept = orig_accept; *accept; accept++)
        {
            if (*s == *accept)
            {
                count++;
                break;
            }
        }

        // If we've scanned the whole accept string and found no match, exit
        if (!*accept)
        {
            break;
        }
        
        s++;
    }

    return count;
}
