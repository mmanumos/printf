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


/**
 * _write_number - get int and return string
 * @integer: pointed array
 *
 * Return: Return string to pointer
 */

int _write_number(va_list integer)
{
	int i = va_arg(integer, int);
	int div = 10, a = 0, c = 0;
	char n = 'f';
	char cad[15];

	if (i < 0)
	{
		n = 't';
		i = -i;
	}
	if (n == 't')
	{
		cad[c] = '-';
		c++;
	}
	if (i > 10)
	{
		while (i / div > 0)
		{
			div *= 10;
		}
		div = div / 10;
		while (div > 0)
		{
			a = i / div;
			a = a % 10;
			cad[c] = (a += 48);
			c++;
			div = div / 10;
		}
		cad[c + 1] = '\0';
	}
	else
	{
		cad[c] = i += 48;
	}
	write(1, cad, _strlen(cad));
	return (_strlen(cad));
}
