#include "main.h"

int check_prime(int n, int i);

/**
 * is_prime_number - checks if a number is prime
 * @n: the number
 *
 * Return: 1 if the number is prime, otherwise 0
 */
int is_prime_number(int n)
{
	if (n < 2)
		return (0);
	return check_prime(n, 2);
}

/**
 * check_prime - checks for primality
 * @n: the number
 * @i: current divisor
 *
 * Return: 1 if prime, otherwise 0
 */
int check_prime(int n, int i)
{
	if (i * i > n)  /* Only check up to the square root of n */
		return (1);
	if (n % i == 0)  /* If n is divisible by i */
		return (0);
	return check_prime(n, i + 1);
}
