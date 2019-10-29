#include "holberton.h"
#include "functions.c"

/**
 *
 *
 */

/**
 * _printf - get the right function to call
 * and send the variables and after write the
 * concatenated buffer
 *
 * Return: Total length of string
 *
 */

int _printf(const char *format, ...)
{

	int i, k, bi = 0;
	va_list par;
	char *buf = malloc(1024);
	char *cad;


	sp print_f[] = {
		{"s", _get_string},
		{"c", _get_char},
		{"i", get_number},
		{"d", get_number},
		{NULL, NULL}
	};


	va_start(par, format);

	i = 0;
	while (format[i] && format)
	{

		if ((format[i] == '%') && (format[i+1] != '%'))
		{

			k = 0;
			while (print_f[k].flag)
			{
				if ((*print_f[k].flag) == format[i + 1])
				{
					cad = print_f[k].f(par);
					buf = _strncat(buf, cad, _strlen(cad));
					bi = bi + _strlen(cad);
				}
				k++;
			}

			i++;
		}

		else
		{
			buf[bi] =  format[i];
			bi++;
		}

		i++;

	}

	buf[bi + 1] = '\0';
	write(1,buf,_strlen(buf));
	return (_strlen(buf));

}
