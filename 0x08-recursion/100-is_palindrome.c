#include "main.h"

int _strlen(char *s);
int check_palindrome(char *s, int len, int idx);

/**
 * is_palindrome - returns 1 if a string is a palindrome and 0 if not
 * @s: the string to check
 *
 * Return: 1 if a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
    int len = _strlen(s);

    if (!*s)
        return (1);

    return (check_palindrome(s, len - 1, 0));
}

/**
 * _strlen - returns the length of a string
 * @s: the string to check
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
    if (!*s)
        return (0);

    return (1 + _strlen(s + 1));
}

/**
 * check_palindrome - checks if a string is a palindrome
 * @s: the string to check
 * @len: the length of the string
 * @idx: the current character index
 *
 * Return: 1 if a palindrome, 0 otherwise
 */
int check_palindrome(char *s, int len, int idx)
{
    if (idx >= len)
        return (1);
    if (s[idx] != s[len - idx])
        return (0);

    return (check_palindrome(s, len, idx + 1));
}
