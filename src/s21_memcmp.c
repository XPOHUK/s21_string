// Copyright [2022] <isleanna>
#include "s21_string.h"

// Сравнивает первые n байтов str1 и str2.
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    const unsigned char *p1 = (const unsigned char *)str1;
    const unsigned char *p2 = (const unsigned char *)str2;
    s21_size_t i = 0;
    int res = 0;

    while (i < n && i <= s21_strlen(str1) && i <= s21_strlen(str2)) {
        if (p1[i] == p2[i]) {
            i++;
        } else {
            res = p1[i] - p2[i];
            break;
        }
    }
    return res;
}
