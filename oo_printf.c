#include "main.h"
#include <stdarg.h>
#include <stdio.h>


/**
 * _printf - prints output according to a format.
 *
 * @format: string that has format specifiers.
 * @Return: number of characters printed (bytes)
 */

int _printf(const char *format, ...)
{
	unsigned int i, bytes = 0;
	
	va_list list;
	va_start(list, format);
	
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				char c = (char)va_arg(list, int);
				bytes += oo_putchar(c);
			}
			else if (format[i] == 's')
			{
				const char *string = va_arg(list, const char *);
				bytes += oo_fputs(string, stdout);
			}
			else if (format[i] == '%')
			{
				bytes += oo_putchar('%');
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				int number = va_arg(list, int);
				bytes += printf("%d", number);
			}
		}
		else
		{
			bytes += oo_putchar(format[i]);
		}
	}
	
	va_end(list);
	return (bytes);
}
