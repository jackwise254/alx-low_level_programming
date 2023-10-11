#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of its own main function
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
    int i, num_bytes;
    char *ptr;

    /* If the number of arguments isn't 2, print an error and exit */
    if (argc != 2)
    {
        printf("Error\n");
        exit(1);
    }

    /* Convert the argument to an int */
    num_bytes = atoi(argv[1]);

    /* If number of bytes is negative, print an error and exit */
    if (num_bytes < 0)
    {
        printf("Error\n");
        exit(2);
    }

    /* Set the pointer to the address of the main function */
    ptr = (char *)main;

    /* Iterate and print opcodes */
    for (i = 0; i < num_bytes; i++)
    {
        printf("%02hhx", ptr[i]);
        if (i < num_bytes - 1)
            printf(" ");
        else
            printf("\n");
    }

    return (0);
}

