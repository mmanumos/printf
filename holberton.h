#ifndef HOLBERTON_H_
#define HOLBERTON_H_
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * struct specifiers - Struct op
 *
 * @flag: Flag to get function
 * @f: The function associated (address)
 */

typedef struct specifiers
{
	char *flag;
	int (*f)(va_list);
} sp;


int _printf(const char *format, ...);

char *(*get_function(char flag))(va_list);
char *_strncat(char *dest, char *src, int n);
int _strlen(char *s);
int _write_string(va_list cad);
int _write_char(va_list cad);
int _write_per(va_list cad);
int _write_number(va_list integer);
int _putchar(char c);

#endif
