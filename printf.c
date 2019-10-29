#include "holberton.h"
/**
 * get_function - Finds the pointer to function
 *
 * @ban: the value tu be compared.
 * Return: The function of corresponding flag.
 */
char *(*get_function(char ban))(va_list)
{
	sp print_f[] = {
		{"s", _get_string},
		{"c", _get_char},
		{"i", get_number},
		{"d", get_number},
		{NULL, NULL}
	};
	int k = 0;

	while (print_f[k].flag != NULL)
	{
		if (*print_f[k].flag == ban)
		{
			return (print_f[k].f);
		}
		k++;
	}
	return (NULL);

}

/**
 * write_buffer - prints the buffer already concatenated
 *
 * @a: The iterator of the buffer.
 * @buffer: The buffer that will be printer.
 */

void write_buffer(int a, char *buffer)
{
	buffer[a + 1] = '\0';
	write(1, buffer, _strlen(buffer));
}


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
	int i = 0, bi = 0;
	va_list par;
	char *buf = malloc(1024);
	char *cad;
	char *(*f)(va_list);

	va_start(par, format);
	if (format[i] == '%' && format[i + 1] == '\0')
		return (-1);
	if (!format)
		return (-1);
	while (format[i] && format)
	{
		if ((format[i] == '%') && (format[i + 1] != '%'))
		{
			f = get_function(format[i + 1]);
			if (f != NULL)
			{
				cad = f(par);
				cad = (cad == 0) ? "(null)" : cad;
				buf = _strncat(buf, cad, _strlen(cad));
				bi = bi + _strlen(cad);
				i++;
			}
			else
			{
				buf[bi] = format[i];
				bi++;
			}
		}
		else if ((format[i] == '%') && (format[i + 1] == '%'))
		{
			buf[bi] = format[i++];
			bi++;
		}
		else
		{
			buf[bi] =  format[i];
			bi++;
		}
		i++;
	}
	write_buffer(bi, buf);
	return (_strlen(buf));
}
