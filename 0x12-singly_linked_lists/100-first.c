#include <stdio.h>

/**
 * myStartupFun - Executes before main function
 */
void __attribute__ ((constructor)) myStartupFun()
{
    printf("You're beat! and yet, you must allow,\n");
    printf("I bore my house upon my back!\n");
}
