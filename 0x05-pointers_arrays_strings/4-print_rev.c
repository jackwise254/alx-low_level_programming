#include "main.h"

/**
 * print_rev - prints a string, in reverse, followed by a new line.
 * @s: the string to be printed in reverse.
 * Return: nothing.
 */
void print_rev(char *s)
{
    int length = 0;

    /* find the length of the string */
    while (s[length] != '\0')
    {
        length++;
    }

    /* start from the last character and move towards the start */
    for (int i = length - 1; i >= 0; i--)
    {
        _putchar(s[i]);
    }

    _putchar('\n');  /* print a new line after the reversed string */
}
