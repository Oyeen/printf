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
