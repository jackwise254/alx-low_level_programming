#include "main.h"

/**
 * _strlen - returns the length of a string.
 * @s: pointer to the string.
 * Return: the length of the string.
 */
int _strlen(char *s)
{
    int length = 0;

    while (*s)  /* loop will run as long as the character s points to is not '\0' */
    {
        length++;
        s++;  /* move to the next character */
    }

    return length;
}
