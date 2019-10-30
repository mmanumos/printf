#include "holberton.h"
#include <stdio.h>

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
 * _strncat - appends string to other string
 * @dest: pointed array
 * @src: String to copy
 * @n: chars number
 * Return: Return string to pointer
 */

char *_strncat(char *dest, char *src, int n)
{
	int cont;
	int cont2;
	int cont3;

	for (cont = 0; dest[cont] != '\0'; cont++)
		;

	for (cont2 = 0; src[cont2] != '\0'; cont2++)
		;
	if (n > cont2)
		n = cont2;

	for (cont3 = 0; cont3 < n; cont3++)
	{
		dest[cont] = src[cont3];
		cont++;
	}
	return (dest);
}


/**
 * _get_char - get char and return string
 * @cad: list with arguments
 *
 * Return: string to pointer
 */

char *_get_char(va_list cad)
{
	char *str = malloc(1);
	char c = va_arg(cad, int);

	if (c == 0)
		write(1, &c, 1);

	str[0] = c;
	return (str);
}



/**
 * _get_string - get string and return string
 * @cad: pointed array
 *
 * Return: Return string to pointer
 */

char *_get_string(va_list cad)
{
	char *str;

	str = va_arg(cad, char *);
	if (str == NULL)
	{
		return (0);
	}
	else
		return (str);
}
/**
 * _get_percentage - get percentage and return percentage
 * @cad: pointed array
 *
 * Return: Return string to pointer
 */
char *_get_percentage(va_list cad __attribute__((__unused__)))
{
	char *str;
	str = "%";
	return (str);
}


/**
 * get_number - get int and return string
 * @integer: pointed array
 *
 * Return: Return string to pointer
 */

char *get_number(va_list integer)
{
	int i = va_arg(integer, int);
	int div = 10, a = 0, c = 0;
	char n = 'f';
	char *cad = malloc(50);

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
	return (cad);
}
/**
 * _calloc - prints buffer in hexa
 * @nmemb: the number of elements that will be in the string
 * @size: the size of the type of data
 * Return: dimensions of the string
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *isize;
	unsigned int a = 0;
	unsigned int mul = nmemb * size;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	isize = (void *)malloc(mul);
	if (isize == NULL)
	{
		return (NULL);
	}
	while (a < mul)
	{
		*(isize + a) = 0;
		a++;
	}
	return (isize);
}
