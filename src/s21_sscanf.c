#include "s21_string.h"
#include <stdarg.h>
#include <stdio.h>   // Только для тестов в main
#include <string.h>  // Только для тестов в main

struct Spec {
    char type;          // Спецификатор: c, d, i, e, E, f, g, G, o, s, u, x, X, p, n, %
    s21_size_t width;   // Ширина
    char length;        // Длина: h, l, L
    int is_star;        // Указана ли звезда после %: 0 - не указана, 1 - указана
    int is_space;       // Состоит ли этот блок только из пробелов
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

s21_size_t parse_save_whitespaces(char *from, struct Spec *s) {
    s21_size_t space_count = s21_strspn(from, " ");
    if (space_count) {
        char *str = (char *) malloc((space_count + 1) * sizeof(char));
        s21_strncpy(str, from, space_count);
        str[space_count] = '\0';
        s->str = str;
        s->is_space = 1;
        *from += space_count;
    }
    return space_count;
}

void match_string(const char* *p_here, char* str, int spaces, int *p_error) {
    if (spaces) {
        s21_size_t space_count = s21_strspn(*p_here, " ");
        *p_here += space_count;
    } else {
        s21_size_t str_len = s21_strlen(str);
        if (s21_strncmp(*p_here, str, str_len)) {
            *p_error = 5;
        } else {
            *p_here += str_len;
        }
    }
}

void parse_spec(char *from, int size, struct Spec *s, int *error) {
    s->str = (char *) malloc ((size + 1) * sizeof(char));
    s21_strncpy(s->str, from, size);
    s->str[size] = '\0';
    s->type = ' ';
    s->width = 0;
    s->length = ' ';
    s->is_star = 0;
    s->is_space = 0;

    char *this = s->str;
    this++;
    if (*this == '%') {
        s->is_star = 0;
        s->type = '%';
    } else {
        if (*this == '*') {
            s->is_star = 1;
            this++;
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
        }
        if (s21_strchr("cdieEfgGosuxXpn%\0", *this) != S21_NULL) {
            s->type = *this;
        } else {
            *error = 6;
        }
    }
    printf("SPEC: %c - %c", s->type, s->length);
    printf(" - %d - %d - %d - '%s'\n", (int)s->width, s->is_star, s->is_space, s->str);
    return;
}

int format_to_array(const char *format, struct Spec **specs, int *error) {
    int result = 0;
    char *from = malloc((s21_strlen(format) + 1) * sizeof(char));
    char *next = S21_NULL;
    from = s21_strcpy(from, format);
    while (*from) {
        int spaces = parse_save_whitespaces(from, *specs + result);
        if (spaces) {
            from += spaces;
        } else {
            from = s21_strchr(from, '%');
            if (from == S21_NULL) {
                break;
            }
            next = s21_strchr(from + 1, '%');
            if (next == S21_NULL) {
                next = from + s21_strlen(from);
            }
            parse_spec(from, next - from, *specs + result, error);
            result++;
            from++;
        }
    }
    if (!specs) {
        result = 0;
    }
    free(from);
    return result;
}

// Считывает форматированный ввод из строки.
int s21_sscanf(const char *str, const char *format, ...) {
    int result = 0;
    if ((str == S21_NULL) || (format == S21_NULL)) {
        result = -1;
    } else {
        int error = 0;
        struct Spec *specs = malloc(s21_strlen(format) / 2 * sizeof(struct Spec));
        int spec_count = format_to_array(format, &specs, &error);

        va_list args;
        va_start(args, format);

        char* here = malloc((s21_strlen(str) + 1) * sizeof(char));
        here[s21_strlen(str)] = '\0';
        const char* const_here = here;
        s21_strcpy(here, str);
        int base = 10;
        printf("=================================================================\n");
        printf("FORMAT: '%s'\n", format);
        printf("STRING: '%s'\n", str);
        for (int i = 0; i < spec_count; i++) {
            char *there;
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
                            if (specs[i].is_star == 0) {
                                result++;
                                *(va_arg(args, long *)) = _var1;
                            }
                        } else if (specs[i].length == 'h') {
                            if (specs[i].is_star == 0) {
                                result++;
                                *(va_arg(args, short *)) = (short) _var1;
                            }
                        } else {
                            if (specs[i].is_star == 0) {
                                result++;
                                *(va_arg(args, int *)) = (int) _var1;
                            }
                        }
                        printf("RESULT: %d - %c - %li\n", result, specs[i].type, _var1);
                        here = there;
                    } else { \
                        error = 1;
                    }
                    break;
                }
                case 'p': {
                    unsigned long long _var2 = strtoull(here, &there, 16);
                    if (here != there) {
                        if (specs[i].is_star == 0) {
                            result++;
                            *(va_arg(args, unsigned long long *)) = _var2;
                        }
                        printf("RESULT: %d - %c - %lli\n", result, specs[i].type, _var2);
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
                            if (specs[i].is_star == 0) {
                                result++;
                                *(va_arg(args, long double *)) = _var3;
                            }
                        } else if (specs[i].length == 'l') {
                            if (specs[i].is_star == 0) {
                                result++;
                                *(va_arg(args, double *)) = _var3;
                            }
                        } else {
                            if (specs[i].is_star == 0) {
                                result++;
                                *(va_arg(args, float *)) = _var3;
                            }
                        }
                        printf("RESULT: %d - %c - '%Lf'\n", result, specs[i].type, _var3);
                        here = there;
                    } else {
                        error = 3;
                    }
                    break;
                }
                case 'c': {
                    s21_size_t count = specs[i].width ? specs[i].width : 1;
                    while (*here == ' ') {
                        here++;
                    }
                    if (s21_strlen(here) >= count) {
                        if (specs[i].is_star == 0) {
                            there = va_arg(args, char *);
                            s21_strncpy(there, here, count);
                            result++;
                        }
                        printf("RESULT: %d - %c - '%s'\n", result, specs[i].type, there);
                        here += count;
                    } else {
                        error = 4;
                    }
                    break;
                }
                case 's': {
                    s21_size_t non_space_count = s21_strcspn(here, " ");
                    s21_size_t count = 0;
                    if (non_space_count < specs[i].width) {
                        count = non_space_count;
                    } else {
                        count = specs[i].width;
                    }
                    if (specs[i].is_star == 0) {
                        there = va_arg(args, char *);
                        s21_strncpy(there, here, count);
                        there[count] = '\0';
                        result++;
                    }
                    printf("RESULT: %d - %c - '%s'\n", result, specs[i].type, there);
                    here += count;
                    break;
                }
                case '\0': {
                    match_string(&const_here, specs[i].str, specs[i].is_space, &error);
                    break;
                }
                case '%': {
                    match_string(&const_here, "%", specs[i].is_space, &error);
                    break;
                }
                case 'n': {
                    *(va_arg(args, int *)) = here - str;
                    break;
                }
                default: {}
            }
            if (error > 0) {
                break;
            }
        }
        va_end(args);
        if (error > 0) {
            result = -1 * error;
        }

        for (int i = 0; i < spec_count; i++) {
            free(specs[i].str);
        }
        free(specs);
    }
    return result;
}

//    int main() {
//        char *fstr = "%x";
//        char *str = "0x519";
//        int a1 = 5, a2 = 5;
//
//        int16_t res1 = s21_sscanf(str, fstr, &a1);
//        int16_t res2 = sscanf(str, fstr, &a2);
//
//        printf("s21_sscanf: %d\t%d\n", res1, a1);
//        printf("    sscanf: %d\t%d\n", res2, a2);
//
//    //    const char fstr[] = "%c %c %c      %c";
//    //    const char str[] = "1 a 3   c           ";
//    //    char a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;
//    //
//    //    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//    //
//    //    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
//    //
//    //    printf("s21_sscanf: %d\t%c\t%c\t%c\t%c\n", res1, a1, b1, c1, d1);
//    //    printf("    sscanf: %d\t%c\t%c\t%c\t%c\n", res2, a2, b2, c2, d2);
//
//    //    ck_assert_int_eq(res1, res2);
//    //    ck_assert_int_eq(a1, a2);
//    //    ck_assert_int_eq(b1, b2);
//    //    ck_assert_int_eq(c1, c2);
//    //    ck_assert_int_eq(d1, d2);
//        return 0;
//    }
