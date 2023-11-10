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
	va_list args;
	int i = 0;
	int c = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			c = c + spec_checker(args, format[i + 1]);
			i++;
		}
		else
		{
			putchar(format[i]);
			c++;
		}
		i++;
	}

	va_end(args);

	return (c);
}
