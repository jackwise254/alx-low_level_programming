/* "Header" contents */
#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
void print_putchar(void);

#endif /* MAIN_H */

/* Implementation */
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

int main(void)
{
    print_putchar();
    return (0);
}
