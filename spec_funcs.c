#include "main.h"

/**
 * spec_checker - runs correct func based on specifier
 *
 * @va_list ap: list of vars
 *
 * @const char s: char (s stands for spec)
 *
 * Return: int (length of var str/char or whatever)
 */
int spec_checker(va_list ap, const char s) {
    int i = 0;
	spec_t specs[] = {
		{'c', print_char},
		{'s', print_str}
	};

	while (i < 2) {
		if (*specs[i].spec == s) {
			return (specs[i].f(ap));
		}
		i++;
	}

	putchar('%');
	if (s == '%') {
		return (1);
	}
	else {
		putchar(s);
		return (2);
	}
}

/**
 * print_char - prints char to stdout
 *
 * @va_list ap: arg, var, the thing to print, a char
 *
 * Return: int (number of chars printed, 1)
 */
int print_char(va_list ap) {
	putchar(va_arg(ap, int));
	return (1);
}

/**
 * print_str - prints str to stdout
 *
 * @va_list ap: arg, var, the thing to print, a str
 *
 * Return: int (c -- stands for chars or conut -- number of chars printed)
 */
int print_str(va_list ap) {
	int c = 0;
	char *str = va_arg(ap, char *);

	while (str[c] != NULL) {
		putchar(str[c]);
		c += 1;
	}

	return (c);
}
