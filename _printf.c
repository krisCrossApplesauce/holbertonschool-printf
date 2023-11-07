#include "main.h"

/**
 * _printf - prints string to stdout
 *
 * @format: char pointer (str)
 *
 * Return: int (c, stands for chars or count, num of chars printed to stdout)
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0;
	int c = 0;

	va_start(ap, format);

	if (format == NULL)
		return (0);

	while (format[i])
	{
		if (format[i] == '%')
		{
			c = c + spec_checker(ap, format[i + 1]);
			i++;
		}
		else
		{
			putchar(format[i]);
			c++;
		}
		i++;
	}

	va_end(ap);

	return (i);
}
