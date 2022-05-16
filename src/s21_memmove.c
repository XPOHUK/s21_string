// Copyright [2022] <isleanna>
#include <stdlib.h>
#include "s21_string.h"

// Еще одна функция для копирования n символов из str2 в str1.
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    char *d;
    const char *s;
    char *tmp;
    s21_size_t i;

    d = (char *)dest;
    s = (const char *)src;
    tmp  = malloc(sizeof(char) * n);
    for (i = 0; i < n; ++i) {
        *(tmp + i) = *(s + i);
        }
        for (i = 0; i < n; ++i) {
            *(d + i) = *(tmp + i);
        }
    free(tmp);
    return (dest);
}
