#include "main.h"

/**
 * _printf - does something
 *
 * @const char *format: char pointer (str)
 *
 * @...: args
 *
 * Return: int (and it also prints to stdout)
 */

int _printf(const char *format, ...)
{
    va_list ap;
    char *arr;
    int i = 0;

    va_start(ap, n);

    arr = va_arg(ap, char *);

    while (format[i] != NULL) {
        if (format[i] == '%') {
            perc_checker(format[i + 1], ...);
            i += 1;
        }
        else {
            putchar(format[i]);
        }
        i += 1;
    }

    va_end(ap);

    return (i);
}
