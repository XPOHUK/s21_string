// Copyright [2022] <isleanna>
#include "s21_string.h"
#include <stdio.h>  // Библиотека для теста

// Находит первый символ в строке str1, который соответствует любому символу,
// указанному в str2.
char *s21_strpbrk(const char *str1, const char *str2) {
    int i = 0;
    int j = 0;
    int pos = 0;
    int flag = 0;

    if ((str1 == NULL) || (str2 == NULL)) {
        return (NULL);
    }
    while (*(str1 + i)) {
        i++;
    }
    pos = i;
    i = 0;
    while (*(str2 + i)) {
        j = 0;
        while (*(str1 + j)) {
            if (str2[i] == str1[j]) {
                if (j <= pos) {
                    pos = j;
                    flag = 1;
                }
            }
            j++;
        }
        i++;
    }
    if (flag == 1) {
        return ((char *)&str1[pos]);
    }
    return (NULL);
}

// Тест функции
int main() {
    char string[] = "Functions that will make our lives easier!";
    char chars[] = "rsaf";
    printf("Find the first matching char in '%s'\n", string);
    printf("Chars '%s'\n", chars);
    char *ptr = s21_strpbrk(string, chars);
    if (ptr != NULL) {
        printf("The first matching char within the string is '%c'\n", *ptr);
    } else {
        printf("No matching chars were found within the string\n");
        }
        return 0;
}
