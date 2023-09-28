#include "main.h"

int find_sqrt(int n, int i);

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number
 *
 * Return: natural square root of n or -1 if n doesn't have one
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (find_sqrt(n, 1));
}

/**
 * find_sqrt - finds the natural square root of a number using recursion
 * @n: the number
 * @i: current guess
 *
 * Return: natural square root or -1 if not found
 */
int find_sqrt(int n, int i)
{
	if (i * i == n)  /* If i is the square root of n */
		return (i);
	if (i * i > n)  /* If square exceeds n and still not equal */
		return (-1);
	return (find_sqrt(n, i + 1));
}
