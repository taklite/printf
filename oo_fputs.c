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
	if (str == NULL || stream == NULL)
		return (EOF); /* Return EOF on error */

	int charCount = 0;

	while (*str != '\0')
	{
		if (fputc(*str, stream) == EOF)
			return (EOF); /* Return EOF if an error occurs during writing */

		charCount++;
		str++;
	}

	return (charCount); /* Return the number of characters written */
}
