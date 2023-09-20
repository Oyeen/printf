#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - Prints the function
 * @format: prints format
 * *@...: elipses
 * *Return: number of chracters printed
 */
int _printf(const char *format, ...)
{
	int count, char_arg;
	char *str_arg;
	va_list args;

	va_start(args, format);
	count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char_arg = va_arg(args, int);

				putchar(char_arg);
				count++;
			}
			else if (*format == 's')
			{
				str_arg = va_arg(args, char *);

				while (*str_arg)
				{
					putchar(*str_arg);
					str_arg++;
					count++;
				}
			} else if (*format == '%')
			{
				putchar('%');
				count++;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
