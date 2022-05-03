// Copyright [2022] <isleanna>
#include "s21_string.h"

// Еще одна функция для копирования n символов из str2 в str1.
void *s21_memmove(void *dest, const void *src, size_t n) {
    char *d;
    const char *s;
    size_t i;

    d = (char *)dest;
    s = (const char *)src;
    i = 0;
    if (d == s) {
        return (dest);
    }
    if (d < s) {
        while (i < n) {
            ((char *)d)[i] = ((const char *)s)[i];
            i++;
        }
    } else if (d > s) {
        while (n > 0) {
            n--;
            ((char *)d)[n] = ((const char *)s)[n];
        }
    }
    return (dest);
}
