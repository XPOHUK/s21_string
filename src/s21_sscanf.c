#include "s21_string.h"
#include <stdio.h>  // Удалить при начале разработки эту заглушку

// Считывает форматированный ввод из строки.
int s21_sscanf(const char *str, const char *format, ...) {
    char *temp;
    int start = 0;
    int result = 0;
    while (*format != '\0') {
        if (*format == ' ') {
            start = 0;
            temp = "";
        } else if (*format == '%') {
            start = 1;
        } else if (start == 1) {
            *temp++ = *format++;
            result = s21_strlen(str);
        }
    }
    return result;
}
