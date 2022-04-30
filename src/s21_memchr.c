// Copyright [2022] <isleanna>
#include "s21_string.h"
#include <stdio.h>  // Библиотека для теста

#include "s21_string.h"
// Выполняет поиск первого вхождения символа c (беззнаковый тип)
// в первых n байтах строки, на которую указывает аргумент str.
void *s21_memchr(const void *str, int c, size_t n) {
    unsigned char *p;
    size_t i;

    i = 0;
    p = (unsigned char *)str;
    while (i < n) {
        if (p[i] == (unsigned char)c)
        return (p + i);
        i++;
    }
    return (NULL);
}

// Тест функции
int main() {
    char s[] = "21school";
    char *ptr = s21_memchr(s, 's', sizeof(s));
    if (ptr != NULL) {
        printf("'s' found at position %ld\n", ptr - s + 1);
        printf("Search character found: %s\n", ptr);
    } else {
        printf("Search character not found\n");
    }
    return 0;
}
