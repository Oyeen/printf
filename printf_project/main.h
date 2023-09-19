#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _putchar(char c);
void to_print_char(int ch_arg);
void to_print_string(char *s_arg);
void to_print_percent(void);
int conversion_specifiers(const char *format, va_list args);
int _printf(const char *format, ...);

#endif
