// Copyright [2022] <isleanna>
#include "s21_string.h"
#include <stdio.h>  // Библиотека для теста

// Возвращает копию строки (str), преобразованной в верхний регистр.
// В случае какой-либо ошибки следует вернуть значение NULL
void *s21_to_upper(const char *str) {
    char *to_upper;

    to_upper = (char *)str;
    while (*to_upper != '\0') {
        if (*to_upper >= 'a' && *to_upper <= 'z') {
            *to_upper = *to_upper - 32;
        }
        ++to_upper;
    }
    return (to_upper);

    const char *result = NULL;
    if (s21_strlen(str) > 0) {
        result = str;
    }
    return (void *)result;
}

// Тест функции
int main() {
    char string[] = "this is sparta!";
    printf("Before '%s'\n", string);
    s21_to_upper(string);
    printf("After '%s'\n", string);
    return 0;
}
