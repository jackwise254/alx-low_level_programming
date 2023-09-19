#include "main.h"

/**
 * _atoi - converts a string to an integer, considering preceding signs.
 * @s: string to convert.
 *
 * Return: the integer value, or 0 if there's no number in the string.
 */
int _atoi(char *s)
{
    int i = 0, sign = 1, result = 0, started = 0;

    while (s[i])
    {
        // If a minus sign is encountered, toggle the sign
        if (s[i] == '-')
        {
            sign *= -1;
        }

        // If a digit is encountered
        if (s[i] >= '0' && s[i] <= '9')
        {
            started = 1;  // set started flag when we see a number
            result = result * 10 + (s[i] - '0') * sign;

            // If the next character is not a digit, break
            if (!(s[i + 1] >= '0' && s[i + 1] <= '9'))
            {
                break;
            }
        }
        else if (started)  // If we've started and encounter a non-digit
        {
            break;
        }

        i++;
    }

    return result;
}
