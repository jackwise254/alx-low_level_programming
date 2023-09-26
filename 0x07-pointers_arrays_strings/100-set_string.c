#include "main.h"

/**
 * set_string - Sets the value of a pointer to a char.
 * @s: A double pointer to a string.
 * @to: The pointer to set to.
 *
 * Return: Void.
 */
void set_string(char **s, char *to)
{
    *s = to;
}
