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
		{'s', print_str},
		{'%', print_perc}
	};

	while (i < 3) {
		if (*specs[i].spec == s) {
			return (specs[i].f(ap));
		}
		i++;
	}

	putchar('%');
	putchar(s);
	return (2);
}
