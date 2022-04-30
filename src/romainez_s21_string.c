#include "romainez_s21_string.h"
#include <stddef.h>
#include <stdio.h>

// Сравнивает две строки с учетом регистра. Если они идентичны, выводит 0
int s21_strcmp(const char *str1, const char *str2) {
    const char *p = str1;
    const char *q = str2;
    while (*p == *q) {
        if (*p == '\0') {
            return 0;
        }
        p++;
        q++;
    }
    return *(unsigned char*)p - *(unsigned char*)q;
}

// Сравнивает не более первых n байтов str1 и str2
int s21_strncmp(const char *str1, const char *str2, size_t n) {
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

int main() {
// Тест для функции s21_strcmp
    char str1[1024]= "school21";
    char str2[1024]= "school21";
    if (s21_strcmp(str1, str2) == 0) {
      printf("Строки идентичны\n");
    } else {
      printf("Строки отличаются\n");
    }

// Тест для функции s21_strncmp
    char str11[1024] = "1234567890";  // Попробуй поменять имя переменной, посмеешься
    char str22[1024] = "1234507890";
    int n = 5;
    if (s21_strncmp(str11, str22, n) == 0) {
        printf("Первые %d символов строк идентичны\n", n);
    } else {
        printf("Первые %d символов строк отличаются\n", n);
    }
    return 0;
}
