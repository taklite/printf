#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * _printf - Custom printf function.
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
		if (*pointer != '%')
			_putchar(*pointer), ++bytes;
		else
		{
			++pointer;
		if (*pointer == '\0')
			break;
		if (*pointer == '%')
			_putchar('%'), ++bytes;
		else if (*pointer == 'd' || *pointer == 'i')
			bytes += printf("%d", va_arg(vars, int));
		}

	va_end(vars);
	return (bytes);
}
