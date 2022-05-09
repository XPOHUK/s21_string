// Copyright [2022] <isleanna>
#include "s21_string.h"

// Возвращает копию строки (str), преобразованной в нижний регистр.
// В случае какой-либо ошибки следует вернуть значение NULL
void *s21_to_lower(const char *str) {
    char *to_lower;

    to_lower = (char *)str;
    while (*to_lower != '\0') {
        if (*to_lower >= 'A' && *to_lower <= 'Z') {
            *to_lower = *to_lower + 32;
        }
        ++to_lower;
    }

    const char *result = NULL;
    if (s21_strlen(str) > 0) {
        result = str;
    }
    return (void *)result;
}
