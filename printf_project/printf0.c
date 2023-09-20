#include <stdio.h>
#include <stdareg.h>

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	int count = 0;
	char ch;
	const char *str;

	while (*format != '\0')

	{
		if (format == '%')
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
