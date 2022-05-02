#include "s21_string.h"
#include "s21_sprintf.h"

#include <stdlib.h>

#include <stdio.h>  // Удалить

// Отправляет форматированный вывод в строку, на которую указывает str.
int s21_sprintf(char *str, const char *format, ...) {
    *str = '\0';
    fmt* fmt = NULL;
    int res = 0;
    res = _parse(format, &fmt);
    if (res == 0) {
        if (fmt == NULL) {
            // Форматов нет, просто копируем строку
            s21_strcpy(str, format);
            printf("%s", str);  // Удалить
        } else {
            while (fmt) {
                printf("begin: %p, end: %p, spec: %c", fmt->begin, fmt->end, fmt->specifier);
                fmt = fmt->next;
            }
        }
    }
    return 0;
}

int _parse(const char *format, fmt** fmt) {
    char* perc;
    int res = 0;
    if (perc = s21_strchr(format, '%')) {
        fmt* nfmt = _new_fmt();
        *fmt = nfmt;
        nfmt->begin = perc;
        if (*(perc + 1) != '%') {
            if (_parse_fmt(nfmt, &format) == 0) {
                nfmt->end = format - 1;
            } else {
                res = 1;
            }
        } else {
            nfmt->end = perc + 1;
            format += 2;
        }
        if (res == 0) {
            while (perc = _strchr(format, '%')) {
                nfmt->next = _new_fmt();
                nfmt = nfmt->next;
                nfmt->begin = perc;
                if (*(perc + 1) != '%') {
                    if (_parse_fmt(nfmt, &format) == 0) {
                        nfmt->end = format - 1;
                    } else {
                        res = 1;
                        break;
                    }
                } else {
                    nfmt->end = perc + 1;
                    format += 2;
                }
            }
        }
    }
    return res;
}

fmt* _new_fmt() {
    fmt* s = malloc(sizeof(fmt));
    s->next = NULL;
    s->begin = NULL;
    s->end = NULL;
    s->flag_left = 0;
    s->flag_sign = 0;
    s->flag_space = 0;
    s->width = 0;
    s->precision = 0;
    s->length = '0';
    s->specifier = '0';
    return s;
}

int _parse_fmt(fmt* fmt, const char** from) {
    int res = 0;
    if (s21_strchr("+- ", **from)) {
        res = _get_flags(fmt, from);
    }
    if (**from > '0' && **from <= '9') {
        int width = 0;
        while (**from >= '0' && **from <= '9') {
            width = width * 10 + (**from - '0');
            (*from)++;
        }
        fmt->width = width;
    }
    if (**from == '.') {
        int precision = 0;
        (*from)++;
        while (**from >= '0' && **from <= '9') {
            precision = precision * 10 + (*format - '0');
            (*from)++;
        }
        fmt->precision = precision;
    }
    if (**from == 'h' || **from == 'l') {
        fmt->length = **from;
        (*from)++;
    }
    if (s21_strchr("cdifsu", **from)) {
        fmt->specifier = **from;
        (*from)++;
    } else {
        res = 1;
    }
    return res;
}

int _get_flags(fmt* fmt, const char** from) {
    int res = 0;
    while (s21_strchr("+- ", **from)) {
        if (**from == '+') {
            if (fmt->sign_flag == 0) {
                fmt->sign_flag = 1;
                fmt->space_flag = 0;
            } else {
                res = 1;
                break;
            }
        } else if (**from == '-') {
            if (fmt->align_flag == 0) {
                fmt->align_flag = 1;
            } else {
                res = 1;
                break;
            }
        } else {
            if (fmt->space_flag == 0) {
                if (fmt->sign_flag == 0) {
                    fmt->space_flag = 1;
                }
            } else {
                res = 1;
                break;
            }
        }
        (*from)++;
    }
    return res;
}
