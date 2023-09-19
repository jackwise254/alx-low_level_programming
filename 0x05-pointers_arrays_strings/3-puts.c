#include "main.h"

/**
 * _puts - prints a string, followed by a new line, to stdout.
 * @str: the string to be printed.
 * Return: nothing.
 */
void _puts(char *str)
{
    while (*str)  /* loop will run as long as the character str points to is not '\0' */
    {
        _putchar(*str);  /* print the character */
        str++;  /* move to the next character */
    }
    _putchar('\n');  /* print a new line after the string */
}
