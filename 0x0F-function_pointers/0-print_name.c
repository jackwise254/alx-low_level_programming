#include "function_pointers.h"
#include <stddef.h> /* For NULL */

/**
 * print_name - Prints a name using the function pointed to by f
 * @name: The name to print
 * @f: The function to use to print the name
 */
void print_name(char *name, void (*f)(char *))
{
    /* Check if name and function pointer are not NULL */
    if (name && f)
    {
        f(name);
    }
}
