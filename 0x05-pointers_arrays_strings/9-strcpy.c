#include "main.h"

/**
 * _strcpy - copies the string pointed to by src, including
 * the terminating null byte, to the buffer pointed to by dest.
 * @dest: pointer to the destination buffer where the string will be copied.
 * @src: pointer to the source string to be copied.
 *
 * Return: pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0')  // copy each character from src to dest
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  // append terminating null byte to the end

    return dest;
}
