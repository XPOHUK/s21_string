#include "s21_sprintf.h"

#include <math.h>
#include <stdio.h>  // TODO(Rambtono) Delete after debug
#include <stdlib.h>
#include <wchar.h>

#include "s21_string.h"

// Отправляет форматированный вывод в строку, на которую указывает str.
int s21_sprintf(char *str, const char *format, ...) {
    *str = '\0';
    const char *f_start = format;
    va_list p;
    va_start(p, format);
    fmt_t *fmt = NULL;
    int res = 0;
    res = _parse(format, &fmt);
    if (res == 0) {
        if (fmt == NULL) {
            // Форматов нет, просто копируем строку
            s21_strcpy(str, format);
        } else {
            _do_output(str, f_start, p, fmt);
        }
    }
    _clear_list(fmt);
    return 0;
}

void _clear_list(fmt_t *fmt) {
    if (fmt) {
        _clear_list(fmt->next);
        free(fmt);
    }
}

int _parse(const char *format, fmt_t **fmt) {
    char *perc;
    int res = 0;
    if ((perc = s21_strchr(format, '%')) != NULL) {
        fmt_t *nfmt = _new_fmt();
        *fmt = nfmt;
        nfmt->begin = perc;
        format = perc + 1;
        if (*format != '%') {
            if (_parse_fmt(nfmt, &format) == 0) {
                nfmt->end = format - 1;
            } else {
                res = 1;
            }
        } else {
            nfmt->end = format;
            format++;
        }
        if (res == 0) {
            while ((perc = s21_strchr(format, '%')) != NULL) {
                nfmt->next = _new_fmt();
                nfmt = nfmt->next;
                nfmt->begin = perc;
                format = perc + 1;
                if (*format != '%') {
                    if (_parse_fmt(nfmt, &format) == 0) {
                        nfmt->end = format - 1;
                    } else {
                        res = 1;
                        break;
                    }
                } else {
                    nfmt->end = format;
                    format++;
                }
            }
        }
    }
    return res;
}

fmt_t *_new_fmt() {
    fmt_t *s = malloc(sizeof(fmt_t));
    s->next = NULL;
    s->begin = NULL;
    s->end = NULL;
    s->flag_left = 0;
    s->flag_sign = 0;
    s->flag_space = 0;
    s->width = 0;
    s->precision = -1;
    s->length = '0';
    s->specifier = '0';
    return s;
}

int _parse_fmt(fmt_t *fmt, const char **from) {
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
        // if (**from == '-') {
        //   precision = -1;
        //   (*from)++;
        //   while (**from >= 0 && **from < -'9') (*from)++;
        // } else {
        while (**from >= '0' && **from <= '9') {
            precision = precision * 10 + (**from - '0');
            (*from)++;
        }
        //}
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

int _get_flags(fmt_t *fmt, const char **from) {
    int res = 0;
    while (s21_strchr("+- ", **from)) {
        if (**from == '+') {
            if (fmt->flag_sign == 0) {
                fmt->flag_sign = 1;
                fmt->flag_space = 0;
            } else {
                res = 1;
            }
        } else if (**from == '-') {
            if (fmt->flag_left == 0) {
                fmt->flag_left = 1;
            } else {
                res = 1;
            }
        } else {
            if (fmt->flag_space == 0) {
                if (fmt->flag_sign == 0) {
                    fmt->flag_space = 1;
                }
            } else {
                res = 1;
            }
        }
        if (res == 1)
            break;
        (*from)++;
    }
    return res;
}

int _do_output(char *str, const char *format, va_list p, fmt_t *fmt) {
    // В зависимости от спецификатора отправляем в соответствующую
    // функцию на конвертацию
    while (fmt) {
        // Копируем обычные символы до формата
        s21_strncat(str, format, fmt->begin - format);
        format = fmt->end + 1;
        char *to_append = NULL;
        if (fmt->end - fmt->begin == 1 && fmt->specifier == '0') {
            to_append = malloc(sizeof(char) * 2);
            to_append[0] = '%';
            to_append[1] = '\0';
        } else {
            switch (fmt->specifier) {
                case 'c':
                    to_append = _char_to_str(p, fmt);
                    break;
                case 'd':
                case 'i':
                    to_append = _int_to_str(p, fmt);
                    break;
                case 'u':
                    to_append = _uint_to_str(p, fmt);
                    break;
                case 's':
                    to_append = _str_to_str(p, fmt);
                    break;
                case 'f':
                    to_append = _float_to_str(p, fmt);
                    break;
            }
            if (fmt->width != 0 && (s21_size_t)fmt->width > s21_strlen(to_append)) {
                // Добавить пробелы слева или справа
                int spaces_len = fmt->width - s21_strlen(to_append);
                char *spaces = malloc(sizeof(char) * (spaces_len + 1));
                for (int i = 0; i < spaces_len; i++) spaces[i] = ' ';
                spaces[spaces_len] = '\0';
                char *new_str = malloc(sizeof(char) * (fmt->width + 1));
                new_str[0] = '\0';
                if (fmt->flag_left) {
                    s21_strcat(new_str, to_append);
                    s21_strcat(new_str, spaces);
                } else {
                    s21_strcat(new_str, spaces);
                    s21_strcat(new_str, to_append);
                }
                free(to_append);
                free(spaces);
                to_append = new_str;
            }
        }
        s21_strcat(str, to_append);
        free(to_append);
        fmt = fmt->next;
    }
    // Скопировать оставшиеся символы
    s21_strcat(str, format);
    return 0;
}

char *_char_to_str(va_list p, fmt_t *fmt) {
    char *res;
    if (fmt->length == 'l') {
        wchar_t *str = malloc(sizeof(wint_t) + sizeof(char));
        str[0] = va_arg(p, wint_t);
        res = (char *)str;
        res = res + sizeof(wint_t);
        *res = '\0';
        res = (char *)str;
    } else {
        res = malloc(sizeof(char) * 2);
        res[0] = va_arg(p, int);
        res[1] = '\0';
    }
    return res;
}

char *_int_to_str(va_list p, fmt_t *fmt) {
    long int arg;
    if (fmt->length == 'l') {
        arg = va_arg(p, long int);
    } else {
        arg = va_arg(p, int);
    }
    char *str = (arg < 0) ? _itoa(-arg) : _itoa(arg);
    int len = s21_strlen(str);
    if (fmt->precision > len) len = len + (fmt->precision - len);
    if ((arg >= 0 && (fmt->flag_sign || fmt->flag_space)) || arg < 0) len++;
    char *res = malloc(sizeof(char) * (len + 1));
    *res = '\0';
    if (arg < 0) {
        s21_strcat(res, "-");
    } else {
        if (fmt->flag_sign) {
            s21_strcat(res, "+");
        } else if (fmt->flag_space) {
            s21_strcat(res, " ");
        }
    }
    // Записать нули если надо
    if (fmt->precision > (int)s21_strlen(str)) {
        for (long unsigned int i = 0; i < fmt->precision - s21_strlen(str); i++) s21_strcat(res, "0");
    }
    s21_strcat(res, str);
    free(str);
    return res;
}

char *_uint_to_str(va_list p, fmt_t *fmt) {
    unsigned long int arg;
    if (fmt->length == 'l') {
        arg = va_arg(p, unsigned long int);
    } else {
        arg = va_arg(p, unsigned int);
    }
    char *str = _itoa(arg);
    int len = s21_strlen(str);
    if (fmt->precision > len) len = len + (fmt->precision - len);
    char *res = malloc(sizeof(char) * (len + 1));
    *res = '\0';
    if (fmt->precision > (int)s21_strlen(str)) {
        for (long unsigned int i = 0; i < fmt->precision - s21_strlen(str); i++) s21_strcat(res, "0");
    }
    s21_strcat(res, str);
    free(str);
    return res;
}

char *_str_to_str(va_list p, fmt_t *fmt) {
    char *str = va_arg(p, char *);
    char *res;
    if (fmt->precision == -1) {
        res = malloc(sizeof(char) * (s21_strlen(str) + 1));
        res = s21_strcpy(res, str);
    } else if (fmt->precision == 0) {
        res = malloc(sizeof(char));
        *res = '\0';
    } else if (fmt->precision < (int)s21_strlen(str)) {
        res = malloc(sizeof(char) * (fmt->precision + 1));
        *res = '\0';
        s21_strncat(res, str, fmt->precision);
    } else {
        res = malloc(sizeof(char) * (s21_strlen(str) + 1));
        res = s21_strcpy(res, str);
    }
    return res;
}

char *_float_to_str(va_list p, fmt_t *fmt) {
    int precision = (fmt->precision == -1) ? 6 : fmt->precision;
    int len = 1;
    double arg = va_arg(p, double);
    arg = _round_double(arg, precision);
    int int_part = (int)arg;
    double float_part = arg - (double)int_part;
    char *int_part_str = (int_part >= 0) ? _itoa(int_part) : _itoa(-int_part);
    len = s21_strlen(int_part_str);
    char *float_part_str = NULL;
    if (precision != 0) {
        float_part = float_part * pow(10, precision);
        float_part_str = (float_part >= 0) ? _itoa((int)float_part) : _itoa((int)-float_part);
        len += s21_strlen(float_part_str) + 1;
    }
    char *res = malloc(sizeof(char) * (len + 2));
    *res = '\0';
    if (arg < 0) {
        s21_strcat(res, "-");
    } else {
        if (fmt->flag_sign) {
            s21_strcat(res, "+");
        } else if (fmt->flag_space) {
            s21_strcat(res, " ");
        }
    }
    s21_strcat(res, int_part_str);
    free(int_part_str);
    if (float_part_str) {
        s21_strcat(res, ".");
        s21_strcat(res, float_part_str);
        free(float_part_str);
    }
    return res;
}

// ТОЛЬКО для положительных чисел!
char *_itoa(long long int i) {
    int dig;
    char *res = malloc(sizeof(char));
    int len = 1;
    long unsigned int k = 0;
    do {
        res = realloc(res, sizeof(char) * (len + 1));
        len++;
        dig = i % 10;
        res[k] = dig + '0';
        k++;
        i /= 10;
    } while (i > 0);
    res[k] = '\0';
    for (k = 0; k < s21_strlen(res) / 2; k++) {
        char tmp = res[k];
        res[k] = res[s21_strlen(res) - k - 1];
        res[s21_strlen(res) - k - 1] = tmp;
    }
    return res;
}

double _round_double(double arg, int precision) {
    return round(arg * pow(10, precision)) / pow(10, precision);
}
