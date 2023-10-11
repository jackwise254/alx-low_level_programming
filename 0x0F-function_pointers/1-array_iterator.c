#include "function_pointers.h"
#include <stddef.h> /* For size_t and NULL */

/**
 * array_iterator - Executes a function on each element of an array
 * @array: Pointer to the array
 * @size: Size of the array
 * @action: Pointer to the function to execute
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
    size_t i;

    /* Check if the array and function pointer are not NULL */
    if (array && action)
    {
        for (i = 0; i < size; i++)
        {
            action(array[i]);
        }
    }
}
