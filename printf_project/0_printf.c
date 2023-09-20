#include "main.h"
/**
 * to_ print_ch - Prints a char
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int to_print_ch(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	char c;

	c = va_arg(args, int);
	return (handle_write_char
			(c, buffer, flags, width, precision, size));
}

/**
 * to_print_string - Prints a string
 * @args: List a number of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates aactive flags
 * @width: get width
 * @precision: Precisio specification
 * @size: Size specifier
 * @size: Number of chars printed
 * Return: On succes 0, failure -1
 */
int to_print_string(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	int len = 0, j;
	char *str;

	str = va_arg(args, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = " ";
	}
	while (str[len] != '\0')
		len++;
	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (j = width - len; j > 0; j--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (j = width - len; j > 0; j--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}
	return (write(1, str, len));
}

/**
 * to_print_percent - prints a pecent sign
 * @args: list of arguments
 * @buffer: Buffer array to handle print
 * @flags: Claculates active flags
 * @width: get width
 * @precision: recision specification
 * @size: Size specifier
 * Return: Number char printed
 */

int to_print_percent(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(args);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
