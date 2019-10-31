#include "holberton.h"

/**
 * _printf - get the right function to call
 * and send the variables and after write the
 * concatenated buffer
 *
 * @format: list with arguments
 *
 * Return: Total length of string
 *
 */
int _printf(const char *format, ...)
{
	int i = 0, len = 0, k, m = 0;
	va_list par;
	sp print_f[] = {
		{"s", _write_string}, {"c", _write_char},
		{"%", _write_per}, {NULL, NULL}
	};
	va_start(par, format);
	if (format == NULL)
		return (-1);

	while (format[i] && format)
	{
		m = 0;
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);

			k = 0;
			while (print_f[k].flag != NULL)
			{
				if (*print_f[k].flag == format[i + 1])
				{
					len += print_f[k].f(par);
					m = 2;
					i++;
				}
				k++;
			}
		}
		if (m == 0)
		{
			_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(par);
	return (len);
}



/**
 * _strlen - return cont
 * @s: string
 *
 * Return: Always 0
 */
int _strlen(char *s)
{
        return ((*s) ? 1 + _strlen(s + 1) : 0);
}


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
        return (write(1, &c, 1));
}
