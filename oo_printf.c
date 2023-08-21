#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Prints output according to a format.
 * @format: String with format specifiers.
 * Return: Number of characters printed (bytes).
 */

int _printf(const char *format, ...)
{
	unsigned int i, bytes = 0;
	va_list list;

	va_start(list, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				bytes += oo_putchar((char)va_arg(list, int));
			else if (format[i] == 's')
				bytes += oo_fputs((va_arg(list, const char *)), stdout);
			else if (format[i] == '%')
				bytes += oo_putchar('%');
			else if (format[i] == 'd' || format[i] == 'i')
				bytes += printf("%d", va_arg(list, int));
		}
		else
			bytes += oo_putchar(format[i]);
	}
	va_end(list);
	return (bytes);
}
