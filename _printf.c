#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

/**
 * _printf - writes output according to a format.
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
			_putchar(*pointer), ++bytes;
		else
		{
			++pointer;
			if (*pointer == '\0')
				break;
			if (*pointer == 'c')
				_putchar(va_arg(vars, int)), ++bytes;
			else if (*pointer == 's')
				while (*(char *)(va_arg(vars, char *)))
					_putchar(*((char *)(va_arg(vars, char *)) + bytes++));
			else if (*pointer == '%')
				_putchar('%'), ++bytes;
		}
	}

	va_end(vars);

	return (bytes);
}
