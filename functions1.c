#include "main.h"

/* FUNCTION TO PRINT THE UNSIGNED NUMBER */
/**
 * print_unsigned - will print an unsigned number
 * @types: the list of arguments
 * @buffer: Buffer array to handle print
 * @flags:  represents the  active flags
 * @width: get width
 * @precision: Precision specification
 * @size: the size specifier
 * Return: Number of characters printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/* FUNCTION TO PRINT UNSIGNED NUMBER IN OCTAL */
/**
 * print_octal - This will print an unsigned number in octal notation
 * @types: The list of arguments
 * @buffer: Buffer array to handle print
 * @flags:  represents the active flags
 * @width: gets width
 * @precision: Precision specification
 * @size: the size specifier
 * Return: Number of characaters printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/* FUNCTION TO PRINT UNSIGNED NUMBER IN HEXADECIMAL */
/**
 * print_hexadecimal - This will print an unsigned number in hexadecimal notation
 * @types: The list of arguments
 * @buffer: Buffer array to handle print
 * @flags:  represents the active flags
 * @width: gets width
 * @precision: Precision specification
 * @size: The size specifier
 * Return: Number of characters printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/* FUNCTION TO PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL */
/**
 * print_hexa_upper - this will print an unsigned number in upper hexadecimal notation
 * @types: the lists of arguments
 * @buffer: Buffer array to handle print
 * @flags:  represents the  active flags
 * @width: gets width
 * @precision: handles precision specification
 * @size: the size specifier
 * Return: The number of characters printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/* Prints hexadecimal number in upper or lower*/
/**
 * print_hexa - Will print ahexadecimal number in upper or lower
 * @types: The list of arguments
 * @map_to: This is the array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Represents the active flags
 * @flag_ch: Represents the active flags
 * @width: gets width
 * @precision: Precision specification
 * @size: The size specifier
 * @size: The size specification
 * Return: Number of characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
