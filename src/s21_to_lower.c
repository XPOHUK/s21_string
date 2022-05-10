// Copyright [2022] <isleanna>
#include "s21_string.h"

// Возвращает копию строки (str), преобразованной в нижний регистр.
// В случае какой-либо ошибки следует вернуть значение NULL
void *s21_to_lower(const char *str) {
    char *copy = malloc(s21_strlen(str) + 1);
    char *start = copy;
    char *end = copy + s21_strlen(str);
    *end = '\0';
    s21_strcpy(copy, str);
    while (*copy != '\0') {
        if (*copy >= 'A' && *copy <= 'Z') {
            *copy = *copy + 32;
        }
        ++copy;
    }
    const char *result = NULL;
    if (s21_strlen(str) > 0) {
        result = start;
    }
    return (void *)result;
    free(start);
}
