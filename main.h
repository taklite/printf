#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int oo_fputs(const char *str, FILE *stream);

int oo_putchar(char);

int _printf(const char *format, ...);

#endif
