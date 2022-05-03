// Copyright [2022] <isleanna>
#include "s21_string.h"

// Копирует символ c (беззнаковый тип) в первые n символов строки,
// на которую указывает аргумент str.
void *s21_memset(void *str, int c, size_t n) {
    char *p;
    size_t i;

    p = str;
    i = 0;
    while (i < n) {
        ((char *)p)[i] = (unsigned char)c;
        i++;
    }
    return (str);
}
