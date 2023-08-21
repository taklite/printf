#include "main.h"
#include <unistd.h>

/**
 * oo_putchar - (char c)
 *
 * @c: char input var
 * Return: 1
 */

int oo_putchar(char c)
{
	return (write(1, &c, 1));
}

