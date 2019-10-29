#include "holberton.h"

/**
 * _strlen - return cont
 * @s: string
 *
 * Return: Always 0
 */
int _strlen(char *s)
{
	return (*s) ? 1 + _strlen(s + 1) : 0;
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
        return (str);
}


/**
 * _get_number - get int and return string
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
