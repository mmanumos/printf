#ifndef HOLBERTON_H_
#define HOLBERTON_H_
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct specifiers - Struct op
 *
 * @flag: Flag to get function
 * @f: The function associated (address)
 */

typedef struct specifiers
{
	char *flag;
	char *(*f)(va_list);
} sp;

int _printf(const char *format, ...);

char *(*get_function(char flag))(va_list);
char *_strncat(char *dest, char *src, int n);
int _strlen(char *s);
char *_get_char(va_list cad);
char *_get_string(va_list cad);
char *get_number(va_list integer);
char *_get_percentage(va_list cad);

#endif
