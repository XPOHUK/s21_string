// Copyright [2022] <isleanna>
// #include "s21_string.h"
#include <stdio.h>  // Библиотека для теста
#include <stdlib.h>  // Библиотека для теста с динамической памятью

// Еще одна функция для копирования n символов из str2 в str1.
void *s21_memmove(void *dest, const void *src, size_t n) {
    char *d;
    const char *s;
    size_t i;

    d = (char *)dest;
    s = (const char *)src;
    i = 0;
    if (d == s) {
        return (dest);
    }
    if (d < s) {
        while (i < n) {
            ((char *)d)[i] = ((const char *)s)[i];
            i++;
        }
    } else if (d > s) {
        while (n > 0) {
            n--;
            ((char *)d)[n] = ((const char *)s)[n];
        }
    }
    return (dest);
}

// void *s21_memmove(void *dest, const void *src, size_t n) {
//     char *d;
//     const char *s;
//     char *tmp;
//     size_t i;

//     d = (char *)dest;
//     s = (const char *)src;
//     tmp  = (char *)malloc(sizeof(char ) * n);
//     i = 0;
//     if (tmp == NULL) {
//         return NULL;
//     } else {
//         for (i = 0; i < n; ++i) {
//             *(tmp + i) = *(s + i);
//         }
//         for (i = 0; i < n; ++i) {
//             *(d + i) = *(tmp + i);
//         }
//         free(tmp);
//     }
//     return (dest);
// }

// Тест функции
int main() {
    char str[42] = "I am relocating from California to Texas.";
    printf("Original:\t%s\n", str);
    printf("Source:\t\t%s\n", str + 5);
    printf("Destination:\t%s\n", str + 16);
    s21_memmove(str + 16, str + 5, 37);
    printf("Result:\t\t%s\n", str);
    return 0;
}
