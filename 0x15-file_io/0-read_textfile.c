#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output.
 * @filename: name of the file to read and print
 * @letters: number of letters it should read and print
 * Return: actual number of letters it could read and print, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;
    ssize_t read_len, write_len;
    char *buffer;

    if (!filename)
        return (0);

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (0);

    buffer = malloc(sizeof(char) * letters);
    if (!buffer)
    {
        close(fd);
        return (0);
    }

    read_len = read(fd, buffer, letters);
    if (read_len == -1)
    {
        free(buffer);
        close(fd);
        return (0);
    }

    write_len = write(STDOUT_FILENO, buffer, read_len);

    free(buffer);
    close(fd);

    if (write_len == read_len)
        return (write_len);

    return (0);
}
