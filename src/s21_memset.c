// Copyright [2022] <isleanna>
#include "s21_string.h"
#include <stdio.h>  // Библиотека для теста

// Копирует символ c (беззнаковый тип) в первые n символов строки,
// на которую указывает аргумент str.
void *s21_memset(void *str, int c, size_t n) {
    char *p;
    size_t i;

    p = str;
    i = 0;
    while (i < n) {
        ((char *)p)[i] = (unsigned char)c;
        i++;
    }
    return (str);
}

// Function to print char of a char array
void printarray(char array[], int n) {
    int i = 0;
    for (i = 0; i < n; i++) {
        printf("%c\n", array[i]);
    }
}

int main() {
    char array[5] = "ABCD";
    // Print array before calling s21_memset
    printarray(array, 5);
    // Calling s21_memset
    s21_memset(array, '0', sizeof(array));
    // Print array after calling s21_memset
    printarray(array, 5);
    return 0;
}
