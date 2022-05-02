// Copyright [2022] <isleanna>
#include "s21_string.h"

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
