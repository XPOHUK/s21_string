// Copyright [2022] <isleanna>
#include "s21_string.h"

// Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке,
// на которую указывает аргумент str.
char *s21_strrchr(const char *str, int c) {
    const char *last_occ;
    unsigned char ch;

    last_occ = NULL;
    ch = c;
    while (*str != '\0') {
        if (*str == ch) {
        last_occ = (char *)str;
        }
        ++str;
    }
    return ((char *)last_occ);
}
