#include "function_pointers.h"
#include <stddef.h> /* For size_t and NULL */

/**
 * int_index - Searches for an integer in an array
 * @array: The array to search
 * @size: The size of the array
 * @cmp: The comparison function
 *
 * Return: The index of the first matching element, or -1 on failure
 */
int int_index(int *array, int size, int (*cmp)(int))
{
    int i;

    if (array == NULL || cmp == NULL || size <= 0)
        return (-1);

    for (i = 0; i < size; i++)
    {
        if (cmp(array[i]))
            return (i);
    }

    return (-1);
}
