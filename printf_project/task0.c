#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * to_printf_char - helper function to printf
 * @ch_arg: character
 *
 * Return: character
 */

void to_printf_char(int ch_arg)
{
	putchar(ch_arg);
}

/**
 * to_printf_string - helpter function of string
 * @s_string: an array of characters
 *
 * Return: On success 0
 */
void to_printf_string(char *s_string)
{
	while (*s_string != '\0')
	{
		putchar(*s_string);
		s_string++;
	}
}

/**
 * to_printf_percent - helper function for percent
 *
 * Return: percent
 */

void to_printf_percent(void)
{
	putchar('%');
}

/**
 * conversion_handlers - conversion specifier
 * @format: format handler
 * @args: variadic list argument
 *
 * Return: On success 0
 */

int conversion_handlers(const char *format, va_list args)
{
	int string, ch_arg;
	char *s_string;

	string = 0;

	if (*format == 'c')
	{
		ch_arg = va_arg(args, int);
		to_printf_char(ch_arg);
		string++;
	}
	else if (*format == 's')
	{
		s_string = va_arg(args, char *);
		to_printf_string(s_string);
		string++;
	}
	else if (*format == '%')
	{
		to_printf_percent();
		string++;
	}

	return (string++);

}

/**
 * _printf - produces output according to a format
 * @format: format string
 * @...: elipsis
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int string;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			string += conversion_handlers(format, args);
		}

		else
		{
			putchar(*format);
			string++;
		}
		format++;
	}

	va_end(args);
	return (string);
}

