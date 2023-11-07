#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct spec - struct for funcs to deal with different vars
 *
 * @char *spec: char (specifier)
 *
 * @int *f: func (to deal the type of var indicated by the specifier)
 */
typedef struct spec {
    char *spec;
    int (*f)(va_list);
} spec_t;

int _printf(const char *format, ...);
int perc_checker(va_list ap, const char c);

int print_char(va_list ap);
int print_str(va_list ap);

#endif
