#include "main.h"

/**
 * _puts - prints a string with newline
 * @str: the string to print
 *
 * Return: (str-a)
 */

int _puts(char *str)
{
	char *a = str; /*declaration of variable */

	while (str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar -writes the character c to stdout
 * @c: the character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and error is set appropriately
 */
int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUG_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

