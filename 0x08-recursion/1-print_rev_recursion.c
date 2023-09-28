#include "main.h"

/**
 * _print_rev_recursion - prints a string in reverse
 * @s: string to print
 *
 * Return: void
 */
void _print_rev_recursion(char *s)
{
    if (*s == '\0')  // Base case
    {
        return;
    }
    
    _print_rev_recursion(s + 1);  // Recursive call for next character
    _putchar(*s);  // Print current character after the recursive call
}
