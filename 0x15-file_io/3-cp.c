#include "main.h"

#define BUFFER_SIZE 1024

/**
 * main - Entry point, copies content from one file to another
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0 on success, or one of the above error codes on failure
 */
int main(int argc, char *argv[])
{
    int from_fd, to_fd, r, w;
    char buffer[BUFFER_SIZE];

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    from_fd = open(argv[1], O_RDONLY);
    if (from_fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    to_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (to_fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        close(from_fd);
        exit(99);
    }

    while ((r = read(from_fd, buffer, BUFFER_SIZE)) > 0)
    {
        w = write(to_fd, buffer, r);
        if (w != r || w == -1)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
            close(from_fd);
            close(to_fd);
            exit(99);
        }
    }

    if (r == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    if (close(from_fd) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from_fd);
        exit(100);
    }

    if (close(to_fd) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to_fd);
        exit(100);
    }

    return (0);
}

