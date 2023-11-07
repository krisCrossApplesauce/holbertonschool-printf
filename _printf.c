#include "main.h"

/**
 * _printf - prints string to stdout
 *
 * @const char *format: char pointer (str)
 *
 * Return: int (c -- stands for chars or count -- number of chars printed to stdout)
 */

int _printf(const char *format, ...)
{
    va_list ap;
    int i = 0;
    int c = 0;

    va_start(ap, format);

    while (format[i] != NULL) {
        if (format[i] == '%') {
            spec_checker(ap, format[i + 1]);
            i += 1;
        }
        else {
            putchar(format[i]);
			c += 1;
        }
        i += 1;
    }

    va_end(ap);

    return (i);
}
