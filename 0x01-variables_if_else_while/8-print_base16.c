#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ch;

	// Print numbers
	for (ch = '0'; ch <= '9'; ch++)
	{
		putchar(ch);
	}

	// Print lowercase letters
	for (ch = 'a'; ch <= 'f'; ch++)
	{
		putchar(ch);
	}
	putchar('\n');

	return (0);
}
