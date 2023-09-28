#include "main.h"

/**
 * _pow_recursion - returns the value of x raised to the power of y
 * @x: the base
 * @y: the exponent
 *
 * Return: value of x raised to y
 */
int _pow_recursion(int x, int y)
{
    if (y < 0)  // If y is negative
    {
        return (-1);
    }
    else if (y == 0)  // Base case
    {
        return (1);
    }
    return x * _pow_recursion(x, y - 1);  // Recursive case
}
