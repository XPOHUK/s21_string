// Copyright [2022] <isleanna>
#include "s21_string.h"

// Возвращает копию строки (str), преобразованной в верхний регистр.
// В случае какой-либо ошибки следует вернуть значение NULL
void *s21_to_upper(const char *str) {
    char *res = NULL;
    if (str) {
        res = malloc(s21_strlen(str) + 1);
        if (res) {
            s21_strcpy(res, str);
            for (char *to_upper = res; *to_upper; ++to_upper) {
                if (*to_upper >= 97 && *to_upper <= 122) {
                    *to_upper = *to_upper - 32;
                }
            }
        }
    }
    return (res);
}
