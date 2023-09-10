#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ch;

	// Printing lowercase alphabet
	for (ch = 'a'; ch <= 'z'; ch++)
	{
		putchar(ch);
	}

	// Printing uppercase alphabet
	for (ch = 'A'; ch <= 'Z'; ch++)
	{
		putchar(ch);
	}
	putchar('\n');

	return (0);
}
