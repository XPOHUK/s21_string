// Copyright [2022] <isleanna>
#include "s21_string.h"
#include <stdio.h>  // Библиотека для теста

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

// Тест функции
int main() {
    const char *string = "Snickersnee";
    char search_for = 'n';
    char *ptr = s21_strrchr(string, search_for);
    if (ptr != NULL) {
        printf("String '%s'\n", string);
        printf("Last occurence of 'n' found at %ld\n", ptr - string + 1);
        printf("Search character found '%s'\n", ptr);
    } else {
        printf("search character not found\n");
    }
    return 0;
}
