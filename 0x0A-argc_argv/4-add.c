#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * is_number - checks if a string is a positive number
 * @s: string to check
 * Return: 1 if true, 0 if false
 */
int is_number(char *s)
{
    if (!*s)
        return (0);
    while (*s)
    {
        if (!isdigit(*s))
            return (0);
        s++;
    }
    return (1);
}

/**
 * main - adds positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 if successful, 1 otherwise
 */
int main(int argc, char *argv[])
{
    int i, sum = 0;

    if (argc == 1)
    {
        printf("0\n");
        return (0);
    }
    for (i = 1; i < argc; i++)
    {
        if (!is_number(argv[i]))
        {
            printf("Error\n");
            return (1);
        }
        sum += atoi(argv[i]);
    }
    printf("%d\n", sum);
    return (0);
}
