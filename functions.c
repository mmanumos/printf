#include "holberton.h"
#include <stdio.h>

/**
 * _write_char - get string and return string
 * @cad: pointed array
 *
 * Return: Return string to pointer
 */

int _write_char(va_list cad)
{
	int c = va_arg(cad, int);

	_putchar(c);
	return (1);
}

/**
 * _write_per - get string and return string
 * @cad: pointed array
 *
 * Return: Return string to pointer
 */

int _write_per(va_list cad)
{
	(void) cad;
	_putchar('%');
	return (1);
}


/**
 * _write_string - get string and return string
 * @cad: pointed array
 *
 * Return: Return string to pointer
 */

int _write_string(va_list cad)
{
	char *str;

	str = va_arg(cad, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		write(1, str, _strlen(str));
		return (_strlen(str));
	}
}
