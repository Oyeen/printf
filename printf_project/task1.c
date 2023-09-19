#include <stdio.h>
#include <stdarg.h>

void my_printf(const char* format, ...) {
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i')) {
            int value = va_arg(args, int);
            printf("%d", value);
            format += 2; // Skip over the conversion specifier
        } else {
            putchar(*format);
            format++;
        }
    }

    va_end(args);
}

int main() {
    int num1 = 42;
    int num2 = -123;
    my_printf("Number 1: %d, Number 2: %i\n", num1, num2);
    return 0;
}

