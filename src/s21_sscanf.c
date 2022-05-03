#include "s21_string.h"
#include <stdarg.h>


// Считывает форматированный ввод из строки.
int s21_sscanf(const char *str, const char *format, ...) {
    va_list args;
    char *specs[1000];
    char *temp;
    int args_count = 0;
    int start = 0;
    int result = 0;

    va_start(args, format);
    while (*format != '\0') {
        if (*format == '%') {
            if (start == 1) {
                args_count++;
                s21_strcpy(specs[args_count], temp);
            }
            start = 1;
            temp = "";
        } else {
            if (start == 1) {
                *temp++ = *format++;
            }
        }
    }

    while (*str != '\0') {
        result++;
    }

    va_end(args);
    return result;
}
