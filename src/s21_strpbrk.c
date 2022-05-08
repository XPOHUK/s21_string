// Copyright [2022] <isleanna>
#include "s21_string.h"
#include <stdio.h>  // Библиотека для теста

// Находит первый символ в строке str1, который соответствует любому символу,
// указанному в str2.
char *s21_strpbrk(const char *str1, const char *str2) {
    char *res = NULL;
    while (*str1 != '\0') {
        if (s21_strchr(str2, *str1)) {
            res = ((char *)str1);
            break;
            } else {
            ++str1;
        }
    }
    return (res);
}

// Тест функции
int main() {
    char string[] = "Functions that will make our lives easier!";
    char chars[] = "rasf";
    printf("Find the first matching char in '%s'\n", string);
    printf("Chars '%s'\n", chars);
    char *ptr = s21_strpbrk(string, chars);
    if (ptr != NULL) {
        printf("The first matching char within the string is '%c'\n", *ptr);
        printf("Found at %ld\n", ptr - string + 1);
    } else {
        printf("No matching chars were found within the string\n");
    }
    return 0;
}
