#include <stdio.h>
#include <stdlib.h>

/**
 * is_number - checks if a string is a positive number
 * @s: string to check
 * Return: 1 if string is a positive number, 0 otherwise
 */
int is_number(char *s)
{
    if (!*s) // empty string
        return (0);

    while (*s)
    {
        if (*s < '0' || *s > '9')
            return (0);
        s++;
    }
    return (1);
}

/**
 * main - adds positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 if successful, 1 if there's a non-digit character in an argument
 */
int main(int argc, char *argv[])
{
    int i, sum = 0;

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
