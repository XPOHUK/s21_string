#include "s21_string.h"
#include "s21_sprintf.h"
#include <stdlib.h>

// Отправляет форматированный вывод в строку, на которую указывает str.
int s21_sprintf(char *str, const char *format, ...) {
    *str = '\0';
    while (*format != '\0') {
        if (*format != '%') {
            *str++ = *format++;
        } else {
            fmt* fmt = _new_fmt();
            _parse_fmt(fmt, &format);
            switch(fmt->specifier) {
                case 'd':
                case 'i':
                    _out_int(&str, fmt);
                    break;
                case 'c':
                case 's':
                case 'f':
                case 'u':
                default:
                    break;
            }
        }
    }
    return 0;
}

int _parse_fmt(fmt* parsed, char** from) {
    int result = 0;
    if (parsed != NULL && from != NULL) {
        result = 1;
    }
    return result;
}

fmt* _new_fmt() {
    fmt* s = malloc(sizeof(fmt));
    s->flag_left = 0;
    s->flag_sign = 0;
    s->flag_space = 0;
    s->width = 0;
    s->precision = 0;
    s->length = 0;
    s->specifier = 0;
    return s;
}

int _parse_fmt(fmt* parsed, char** from) {
    return 0;
}
