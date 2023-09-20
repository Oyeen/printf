#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - prints output
 * @format: format
 * @...: elpisis
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int variable;
	char ch;
	char *str;
	va_list list;

	variable = 0;

	if (format == NULL)
		return (-1);
	va_start(list, format);
	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			variable++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				putchar('%');
				variable++;
			}
			else if (*format == 'c')
			{
				ch = va_arg(list, int);
				putchar(ch);
				variable++;
			}
			else if (*format == 's')
			{
				str = va_arg(list, char *);
				while (*str)
				{
					putchar (*str);
					str++;
					variable++;
				}
			}
		}
		format++;
	}
	va_end(list);
	return (variable);
}
