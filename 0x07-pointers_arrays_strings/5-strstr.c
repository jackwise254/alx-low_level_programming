#include "main.h"

/**
 * _strstr - Locates a substring.
 * @haystack: The main string to be scanned.
 * @needle: The substring to be located.
 *
 * Return: A pointer to the beginning of the located substring,
 *         or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
    char *start_haystack;
    char *start_needle;

    while (*haystack)
    {
        start_haystack = haystack;
        start_needle = needle;

        while (*start_haystack == *start_needle && *start_needle && *start_haystack)
        {
            start_haystack++;
            start_needle++;
        }

        if (!*start_needle)
        {
            return haystack;
        }

        haystack++;
    }

    return NULL;
}
