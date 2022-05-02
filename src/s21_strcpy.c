// Copyright [2022] <romainez>
#include "s21_string.h"

// Копирует строку, на которую указывает src, в dest.
char *s21_strcpy(char *dest, const char *src) {
    dest = (char *)dest;
    src = (const char *)src;
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
