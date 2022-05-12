// Copyright [2022] <isleanna>
#include "s21_string.h"
#include <stdio.h>  // Библиотека для теста
#include <stdlib.h>  // Библиотека для теста 

// Возвращает новую строку, в которой указанная строка (str)
// вставлена в указанную позицию (start_index) в данной строке (src).
// В случае какой-либо ошибки следует вернуть значение NULL
void *s21_insert(const char *src, const char *str, size_t start_index) {
    char *res = malloc((s21_strlen(src) + s21_strlen(str) + 1));
    s21_strncpy(res, src, start_index);
    *(res + start_index) = '\0';
    s21_strcat(res, str);
    s21_strcat(res, src + start_index);
    return ((void *)res);
}

// Тест функции
int main() {
    char string[] = "Error. Press F1 to continue.";
    printf("Before insertion '%s'\n", string);
    char *new_string = s21_insert(string, "No keyboard. ", 7);
    printf("After insertion '%s'\n", new_string);
    free(new_string);
    return (0);
}
