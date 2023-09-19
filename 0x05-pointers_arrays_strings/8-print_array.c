#include "main.h"
#include <stdio.h>

/**
 * print_array - prints n elements of an array of integers, followed by a new line.
 * @a: pointer to the array.
 * @n: number of elements of the array to be printed.
 * Return: nothing.
 */
void print_array(int *a, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        
        if (i < n - 1)  // to ensure comma is not printed after the last element
        {
            printf(", ");
        }
    }
    printf("\n");
}
