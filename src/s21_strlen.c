// Copyright [2022] <isleanna>
#include "s21_string.h"

// Вычисляет длину строки str, не включая завершающий нулевой символ.
size_t s21_strlen(const char *str) {
    size_t i;

    i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
