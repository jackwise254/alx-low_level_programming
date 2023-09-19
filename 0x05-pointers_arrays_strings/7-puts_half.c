#include "main.h"

/**
 * puts_half - prints the second half of a string, followed by a new line.
 * @str: the string to be printed.
 * Return: nothing.
 */
void puts_half(char *str)
{
    int length = 0, i, start;

    // Calculate the length of the string
    while (str[length] != '\0')
    {
        length++;
    }

    // Determine starting point based on even or odd length
    if (length % 2 == 0)
    {
        start = length / 2;
    }
    else
    {
        start = (length - 1) / 2;
    }

    // Print the second half of the string
    for (i = start; i < length; i++)
    {
        _putchar(str[i]);
    }

    _putchar('\n');  // print a new line after printing the string
}
