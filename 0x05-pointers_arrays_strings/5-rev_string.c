#include "main.h"

/**
 * rev_string - reverses a string in-place.
 * @s: the string to be reversed.
 * Return: nothing.
 */
void rev_string(char *s)
{
    int length = 0, i;
    char temp;

    /* find the length of the string */
    while (s[length] != '\0')
    {
        length++;
    }

    /* use two-pointer approach to reverse the string */
    for (i = 0; i < length / 2; i++)
    {
        temp = s[i];
        s[i] = s[length - 1 - i];
        s[length - 1 - i] = temp;
    }
}
