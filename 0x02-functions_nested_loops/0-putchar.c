#include "main.h"

void print_putchar(void)
{
    char *str = "_putchar";
    
    while (*str)
    {
        _putchar(*str);
        str++;
    }
    _putchar('\n');
}
