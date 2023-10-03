#include <stdio.h>

/**
 * main - prints the number of arguments passed to it.
 * @argc: argument count.
 * @argv: argument vector (unused).
 * 
 * Return: 0 if successful.
 */
int main(int argc, char *argv[])
{
    (void)argv;  /* unused parameter */

    printf("%d\n", argc - 1);
    return (0);
}
