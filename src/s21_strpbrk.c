// Copyright [2022] <isleanna>
#include "s21_string.h"

// Находит первый символ в строке str1, который соответствует любому символу,
// указанному в str2.
char *s21_strpbrk(const char *str1, const char *str2) {
    char *res;

    int i = 0;
    int j = 0;
    int pos = 0;
    int flag = 0;
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
        res = ((char *)&str1[pos]);
    }
    return ((char *)res);
}
