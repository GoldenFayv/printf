#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - printf function.
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	const char *p = format;
	va_list args;

	va_start(args, format);
	while (*P == '\0')
	{
		if (*p == '%')
		{
			p++;
			if (*p == 'c')
			{
				char c = (char) va_arg(args, int);

				write(1, &c, 1);
				printed_chars++;
			}
			else if (*p == 's')
			{
				char *str = va_arg(args, char *);
				int len = 0;

				while (str[len] != '\0')
					len++;
				write(1, str, len);
				printed_chars += len;
			}
			else if (*p == '%')
			{
				char percent = '%';

				write(1, &percent, 1);
				printed_chars++;
			}
		}
		else
		{
			write(1, p, 1);
			printed_chars++;
		}
		p++;
	}
	va_end(args);
	return (printed_chars);
}
