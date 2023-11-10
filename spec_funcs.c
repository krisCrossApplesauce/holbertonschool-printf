#include "main.h"

/**
 * spec_checker - runs correct func based on specifier
 *
 * @ap: list of vars
 *
 * @s: char (s stands for spec)
 *
 * Return: int (length of var str/char or whatever)
 */
int spec_checker(va_list args, char s)
{
	int i = 0;
	spec_t specs[] = {
		{ "c", print_char },
		{ "s", print_str },
		{ "d", print_int },
		{ "i", print_int }
	};

	while (i < 4)
	{
		if (*specs[i].spec == s)
			return (specs[i].f(args));
		i++;
	}

	if (s == '\0')
		return (0);
	putchar('%');
	if (s == '%')
		return (1);
	putchar(s);
	return (2);
}

/**
 * print_char - prints char to stdout
 *
 * @ap: arg, var, the thing to print, a char
 *
 * Return: int (number of chars printed, 1)
 */
int print_char(va_list args)
{
	putchar(va_arg(args, int));
	return (1);
}

/**
 * print_str - prints str to stdout
 *
 * @ap: arg, var, the thing to print, a str
 *
 * Return: int (c -- stands for chars or count -- number of chars printed)
 */
int print_str(va_list args)
{
	int c = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	while (str[c])
	{
		putchar(str[c]);
		c++;
	}

	return (c);
}

/**
 * print_int - prints int to stdout
 *
 * @ap: arg, var, the thing to print, an int
 *
 * Return: int (c -- stands for chars or count -- number of chars printed)
 */
int print_int(va_list args)
{
	int i, ii, a = 0, n, not_n, x, c = 0;

	n = va_arg(args, int);

	if (n < 0)
	{
		putchar('-');
		n = n * -1;
		a = 1;
	}

	not_n = n;

	while (not_n > 0)
	{
		c++;
		not_n = (not_n / 10);
	}

	if (c == 0)
		return (0);

	for (i = c - 1; i >= 0; i--)
	{
		x = 1;

		for (ii = 0; ii < i; ii++)
			x = x * 10;

		putchar((n / x) + '0');
		n = (n % x);
	}

	if (a == 1)
		c = c + 1;

	return (c);
}
