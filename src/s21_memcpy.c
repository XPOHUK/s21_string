// Copyright [2022] <isleanna>
#include "s21_string.h"

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
    return(dest);
}
