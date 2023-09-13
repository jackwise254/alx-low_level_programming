#include "main.h"

/**
 * times_table - Prints the 9 times table.
 *
 * Return: void.
 */
void times_table(void)
{
    int i, j, result;

    for (i = 0; i <= 9; i++)
    {
        for (j = 0; j <= 9; j++)
        {
            result = i * j;
            if (j != 0)
            {
                _putchar(','); 
                _putchar(' ');
                if (result < 10)
                    _putchar(' '); // Add extra space for single digits
            }
            if (result >= 10)
            {
                _putchar(result / 10 + '0'); // Print tens place
                _putchar(result % 10 + '0'); // Print ones place
            }
            else
            {
                _putchar(result + '0');
            }
        }
        _putchar('\n');
    }
}
