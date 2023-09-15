#include "main.h"

/**
 * largest_number - returns the largest of 3 numbers
 * @a: first integer
 * @b: second integer
 * @c: third integer
 * Return: largest number
 */

int largest_number(int a, int b, int c)
{
    int largest;

    if (a >= b && a >= c) // if a is greater than or equal to both b and c
    {
        largest = a;
    }
    else if (b >= a && b >= c) // if b is greater than or equal to both a and c
    {
        largest = b;
    }
    else // c is the largest
    {
        largest = c;
    }

    return (largest);
}
