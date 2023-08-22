#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Prints output according to a format.
 * @format: String with format specifiers.
 * @...: Set of arguments for format.
 * Return: Number of characters printed (bytes).
 */
int _printf(const char *format, ...)
{
	va_list vars;
	int bytes = 0;
	const char *pointer;

	va_start(vars, format);

	for (pointer = format; *pointer; ++pointer)
	{
		if (*pointer != '%')
			oo_putchar(*pointer), ++bytes;
		else
		{
			++pointer;
			if (*pointer == '\0')
				break;
			if (*pointer == 'c')
				oo_putchar(va_arg(vars, int)), ++bytes;
			else if (*pointer == 's')
				bytes += printf("%s", va_arg(vars, char *));
			else if (*pointer == '%')
				oo_putchar('%'), ++bytes;
			else if (*pointer == 'd' || *pointer == 'i')
				bytes += printf("%d", va_arg(vars, int));
			else
				oo_putchar('%'), putchar(*pointer), bytes += 2;
		}
	}

	va_end(vars);
	return (bytes);
}
