#include "main.h"
#include <stdio.h>

/**
 * oo_fputs - Writes a string to a FILE stream.
 *
 * @str: Pointer to the string to be written
 * @stream: Pointer to the FILE stream where the string will be written
 *
 * Return: Number of characters written on success, EOF on error
 */
int oo_fputs(const char *str, FILE *stream)
{
	int charCount = 0;

	if (str == NULL || stream == NULL)
		return (EOF);


	while (*str != '\0')
	{
		if (fputc(*str, stream) == EOF)
			return (EOF);

		charCount++;
		str++;
	}

	return (charCount);
}
