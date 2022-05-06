// Copyright [2022] <isleanna>
#include "s21_string.h"

// Выполняет поиск первого вхождения символа c (беззнаковый тип)
// в первых n байтах строки, на которую указывает аргумент str.
void *s21_memchr(const void *str, int c, size_t n) {
    unsigned char *p;
    unsigned char *res;
    size_t i;

    i = 0;
    p = (unsigned char *)str;
    while (i < n) {
        if (p[i] == (unsigned char)c) {
            res = p + i;
        }
        i++;
    }
    return ((void *)res);
}
