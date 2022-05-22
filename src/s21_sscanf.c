#include "s21_string.h"
#include <stdarg.h>
#include <math.h>
#include <float.h>

struct Spec {
    char type;          // Спецификатор: c, d, i, e, E, f, g, G, o, s, u, x, X, p, n
    s21_size_t width;   // Ширина
    char length;        // Длина: h, l, L
    int is_star;        // Указана ли звезда после %: 0 - не указана, 1 - указана
    char *str;          // Указатель на блок строки, относящейся к этому спецификатору
};

int string_to_int(char *string) {
    int result = -1;
    int sign = 1;
    if (string) {
        result = 0;
        if (*string == '+') {
            string++;
        } else if (*string == '-') {
            sign = -1;
            string++;
        }
        while (*string) {
            if (*string < '0' || *string > '1') {
                break;
            } else {
                result = result * 10 + *string - '0';
            }
        }
    }
    return sign * result;
}

void match_string(const char* *p_here, char* str, int *p_error) {
    s21_size_t str_len = s21_strlen(str);
    if (s21_strncmp(*p_here, str, str_len)) {
        *p_error = 5;
    } else {
        *p_here += str_len;
    }
}

void parse_spec(char *from, int size, struct Spec *s) {
    s->str = (char *) malloc ((size + 1) * sizeof(char));
    s21_strncpy(s->str, from, size);
    s->str[size] = '\0';

    char *this = s->str;
    if (*this == '*') {
        s->is_star = 1;
    } else {
        s->is_star = 0;
        if (*this >= '0' && *this <= '1') {
            s->width = string_to_int(this);
            while (*this >= '0' && *this <= '1') {
                this++;
            }
        }
        if (*this == 'h' || *this == 'l' || *this == 'L') {
            s->length = *this;
            this++;
        }
        if (s21_strchr("cdieEfgGosuxXpn%", *this) != S21_NULL) {
            s->type = *this;
        }
    }
    return;
}

int format_to_array(const char *format, struct Spec **specs) {
    int result = 0;
    char *from = malloc((s21_strlen(format) + 1) * sizeof(char));
    char *next = S21_NULL;
    from = s21_strcpy(from, format);
    while (*from) {
        from = s21_strchr(from, '%');
        if (from == S21_NULL) {
            break;
        }
        next = s21_strchr(from + 1, '%');
        if (next == S21_NULL) {
            next = from + s21_strlen(from) - 1;
        }
        parse_spec(from, next - from, *specs + result);
        result++;
        from++;
    }
    if (!specs) {
        result = 0;
    }
    free(from);
    // free(next);
    return result;
}

// Считывает форматированный ввод из строки.
int s21_sscanf(const char *str, const char *format, ...) {
    int result = 0;
    int error = 0;
    struct Spec *specs = malloc(s21_strlen(format) / 2 * sizeof(struct Spec));
    int spec_count = format_to_array(format, &specs);

    va_list args;
    va_start(args, format);

    const char* here = str;
    char *there;
    int base = 10;
    for (int i = 0; i < spec_count; i++) {
        switch (specs[i].type) {
            case 'o': case 'x': case 'X': case 'd': case 'i': case 'u': {
                if (specs[i].type == 'o') {
                    base = 8;
                } else if (specs[i].type == 'x' || specs[i].type == 'X') {
                    base = 16;
                }
                long _var1 = strtol(here, &there, base);
                if (here != there) {
                    if (specs[i].length == 'l') {
                        if (!(specs[i].is_star)) {
                            ++result;
                            *(va_arg(args, long *)) = _var1;
                        }
                    } else if (specs[i].length == 'h') {
                        if (!(specs[i].is_star)) {
                            ++result;
                            *(va_arg(args, short *)) = (short) _var1;
                        }
                    } else {
                        if (!(specs[i].is_star)) {
                            ++result;
                            *(va_arg(args, int *)) = (int) _var1;
                        }
                    }
                    here = there;
                } else { \
                    error = 1;
                }
                break;
            }
            case 'p': {
                unsigned long long _var2 = strtoull(here, &there, 16);
                if (here != there) {
                    if (!(specs[i].is_star)) {
                        ++result;
                        *(va_arg(args, unsigned long long *)) = _var2;
                    }
                    here = there;
                } else {
                    error = 2;
                }
                break;
            }
            case 'f': case 'F': case 'g': case 'G': case 'e': case 'E': {
                long double _var3 = strtold(here, &there);
                if (here != there) {
                    if (specs[i].length == 'L') {
                        if (!(specs[i].is_star)) {
                            ++result;
                            *(va_arg(args, long double *)) = _var3;
                        }
                    } else if (specs[i].length == 'l') {
                        if (!(specs[i].is_star)) {
                            ++result;
                            *(va_arg(args, double *)) = _var3;
                        }
                    } else {
                        if (!(specs[i].is_star)) {
                            ++result;
                            *(va_arg(args, float *)) = _var3;
                        }
                    }
                    here = there;
                } else {
                    error = 3;
                }
                break;
            }
            case 'c': {
                s21_size_t count = specs[i].width ? specs[i].width : 1;
                if (s21_strlen(here) >= count) {
                    if (!(specs[i].is_star)) {
                      there = va_arg(args, char *);
                      s21_strncpy(there, here, count);
                      ++result;
                    }
                    here += count;
                } else {
                    error = 4;
                }
                break;
            }
            case 's': {
                s21_size_t non_space_count = s21_strcspn(here, " ");
                s21_size_t count_width = 0;
                if (non_space_count < specs[i].width) {
                    count_width = non_space_count;
                } else {
                    count_width = specs[i].width;
                }
                s21_size_t count = specs[i].width ? count_width : non_space_count;
                if (!(specs[i].is_star)) {
                  there = va_arg(args, char *);
                  s21_strncpy(there, here, count);
                  ++result;
                }
                here += count;
                break;
            }
            case '\0': {
                match_string(&here, specs[i].str, &error);
                break;
            }
            case '%': {
                match_string(&here, "%", &error);
                break;
            }
            case 'n': {
                *(va_arg(args, int *)) = here - str;
                break;
            }
            default: {}
        }
    }
    if (error > 0) {
        result = -1 * error;
    }

    va_end(args);
    free(specs);
    return result;
}
