// Copyright [2022] <isleanna>
#include "s21_string.h"
#include <stdio.h>  // Библиотека для теста

// Вычисляет длину строки str, не включая завершающий нулевой символ.
size_t s21_strlen(const char *str) {
    size_t i;

    i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

// Тест функции
int main() {
    char s[15]="Abibliophobia";
    printf("The length of the string is %zu\n", s21_strlen(s));
    return 0;
}
