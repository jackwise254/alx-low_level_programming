#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    char num;

    // Print numbers 0 through 9
    for (num = '0'; num <= '9'; num++)
    {
        putchar(num);
    }

    // Print letters a through f
    for (num = 'a'; num <= 'f'; num++)
    {
        putchar(num);
    }
    putchar('\n');

    return (0);
}
