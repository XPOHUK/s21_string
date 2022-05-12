// Copyright [2022] <isleanna>
#include "s21_string.h"
#include <stdio.h>  // Библиотека для теста
#include <stdlib.h>  // Библиотека для теста

// Возвращает новую строку, в которой удаляются все начальные и конечные
// вхождения набора заданных символов (trim_chars) из данной строки (src).
// В случае какой-либо ошибки следует вернуть значение NULL
void *s21_trim(const char *src, const char *trim_chars) {
    size_t lead = 0;
    size_t trail = s21_strlen(src);
    char *res = NULL;
    size_t i = 0;
    while (src[lead] && s21_strchr(trim_chars, src[lead])) {
        lead++;
    }
    while (trail > lead && s21_strchr(trim_chars, src[trail - 1])) {
        trail--;
    }
    res = malloc(sizeof(*src) * (trail - lead + 1));
    while (lead < trail) {
        res[i++] = src[lead++];
    }
    res[i] = '\0';
    return ((void *)res);
}

// Тест функции
int main() {
    char string[] = "./Nincompooper";
    char trim_chars[] = "re/.";
    printf("Original string '%s'\n", string);
    printf("Trim chars '%s'\n", trim_chars);
    char *new_string = s21_trim(string, trim_chars);
    printf("New string '%s'\n", new_string);
    free(new_string);
    return (0);
}
