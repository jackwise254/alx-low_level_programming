#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num;

	for (num = 48; num < 58; num++)  /* ASCII values for 0-9 */
		putchar(num);

	for (num = 97; num < 103; num++)  /* ASCII values for a-f */
		putchar(num);

	putchar('\n');

	return (0);
}
