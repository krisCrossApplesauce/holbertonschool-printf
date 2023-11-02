#include <stdlib.h>
#include <stdio.h>
#include <main.h>

/**
* _printf - does something
*
* @const char *format: char pointer (str)
*
* @...: args
*
* Return: int (and it also prints to stdout)
*/

int _printf(const char *format, ...) {
    int i = 0;
    while (format[i] != NULL) {
        if (format[i] == '%') {
            checker_func(format[i], format[i + 1], ...);
            i += 1;
        }
        else {
            putchar(format[i]);
        }
        i += 1;
    }
}
