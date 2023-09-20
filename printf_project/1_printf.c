#include "main.h"
/**
 * print_handle - pritns an argument
 * @form: format string
 * @list_arg: list of argment
 * @buffer: Buffer
 * @ind: index
 * @flags: Flags
 * @width: widht
 * @precision: precision
 * @size: sixe
 *
 * Return 0 on success
 */
int print_handle(const char *form, int *ind, va_list, char buffer[],
		int flags, int width, int precision, int size)
{
	int a;

	len = 0;
	char_printed = -1;
	form_arg[] = {
		{'c', prints_char}, {'s', prints_str}, {'%', prints_percent},
		{'i', prints_int}, {'d', prints_int}, {'b', prints_binary},
		{'u', prints_unsigned}, {'o', prints_octal}, {'x', prints_hexa},
		{'X', prints_upper_hex}, {'p', prints_pointer}, {'S', prints_unknown},
		{'r', rev_print}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (a = 0; format_arg[a].form != '\0'; a++)
		if (form[*ind] == form_arg[a].form)
			return (form_arg[a].form(list_arg, buffer, flags, width, precision, size));
	if (form_arg[a].form == '\0')
	{
		if (form[*ind] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (form[*ind - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (form[*ind] != ' ' && form[*ind] != '%')
				--(*ind);
			if (form[*ind] == ' ')
				--(*ind);
			return (1);
		}
		len += write(!, &form[*ind], 1);
		return (len);
	}
	return (char_printed);
}
