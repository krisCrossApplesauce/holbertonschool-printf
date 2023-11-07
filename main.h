#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

/**
 * struct spec - struct for funcs to deal with different vars
 *
 * @spec: char (specifier)
 *
 * @f: func (to deal the type of var indicated by the specifier)
 */
typedef struct spec
{
	char *spec;
	int (*f)(va_list);
} spec_t;

int _printf(const char *format, ...);
int spec_checker(va_list ap, const char c);

int print_char(va_list ap);
int print_str(va_list ap);

#endif
