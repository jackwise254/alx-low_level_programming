#include "main.h"

/**
 * main - Entry point, displays the information contained in the ELF header
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0 on success, or one of the above error codes on failure
 */
int main(int argc, char *argv[])
{
    int fd;
    unsigned char e_ident[EI_NIDENT];
    Elf64_Ehdr header;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1 || read(fd, e_ident, EI_NIDENT) != EI_NIDENT ||
        read(fd, &header, sizeof(header)) != sizeof(header))
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        close(fd);
        exit(98);
    }

    if (e_ident[0] != 0x7f || e_ident[1] != 'E' ||
        e_ident[2] != 'L' || e_ident[3] != 'F')
    {
        dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
        close(fd);
        exit(98);
    }

    printf("ELF Header:\n");
    close(fd);
    return (0);
}

