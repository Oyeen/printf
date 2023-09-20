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
	va_list args;
	int count;
	char ch;
	const char *str;

	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					ch = (char) va_arg(args, int);
					putchar(ch);
					count++;
					break;
				case 's':
					str = va_arg(args, const char *);
					while (*str != '\0')
					{
						putchar(*str);
						str++;
						count++;
					}
					break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					putchar(*format);
					count += 2;
					break;
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
