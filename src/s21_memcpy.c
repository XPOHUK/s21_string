// Copyright [2022] <isleanna>
#include "s21_string.h"
#include <stdio.h>  // Библиотека для теста

// Копирует n символов из src в dest.
void *s21_memcpy(void *dest, const void *src, size_t n) {
    char *dest2;
    const char *src2;
    size_t i;

    dest2 = (char *)dest;
    src2 = (const char *)src;
    i = 0;
    while (i < n) {
        dest2[i] = src2[i];
        i++;
    }
    return (dest);
}

// Тест функции
int main() {
    char s[25] = "Deadline is approaching!";
    char d[25] = {0};
    s21_memcpy(d, s, sizeof(s));
    printf("%s\n", d);
    return 0;
}
