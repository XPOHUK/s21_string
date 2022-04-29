// Copyright [2022] <isleanna>
#include "s21_string.h"
#include <stdio.h>  // Библиотека для теста

// Сравнивает первые n байтов str1 и str2.
int s21_memcmp(const void *str1, const void *str2, size_t n) {
    const unsigned char *p1;
    const unsigned char *p2;
    size_t i;

    p1 = (const unsigned char *)str1;
    p2 = (const unsigned char *)str2;
    i = 0;
    while (i < n) {
        if (p1[i] != p2[i]) {
            return (p1[i] - p2[i]);
        }
        i++;
    }
    return 0;
}

// Тест функции
int main() {
    int result = 0;
    // If str1 and str2 are equal
    result = s21_memcmp("abc", "abc", 2);
    printf("result = %d\n", result);
    // If first char of str1 is bigger than str2
    result = s21_memcmp("bca", "abc", 2);
    printf("result = %d\n", result);
    // If first char of str1 is smaller than str2
    result = s21_memcmp("abc", "bca", 2);
    printf("result = %d\n", result);
    return 0;
}
