#include "romainez_s21_string.h"
#include <stdio.h>

// Сравнивает две строки с учетом регистра. Если они идентичны, выводит 0.
int strcmp(const char *str1, const char *str2) {
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

// Тест
int main() {
    char str1[1024]= "school21";
    char str2[1024]= "school21";

// Сравниваем две строки
    if (strcmp(str1, str2) == 0) {
      printf("Строки идентичны\n");
    } else {
      printf("Строки отличаются\n");
    }
    return 0;
}
