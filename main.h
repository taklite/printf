#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int oo_fputs(const char *str, FILE *stream);
int oo_putchar(char c);
int _printf(const char *format, ...);

#endif
