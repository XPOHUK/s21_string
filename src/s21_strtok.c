#include <string.h>  // Удалить при начале разработки эту заглушку

#include "s21_string.h"

// Разбивает строку str на ряд токенов, разделенных delim.

char *ptr;

char *s21_strtok(char *str, const char *delim) {
    if (str) {
        ptr = s21_strpbrk(str, delim) + 1;
    } else if (ptr) {
        str = ptr;
        ptr = (s21_strpbrk(str, delim)) ? s21_strpbrk(str, delim) + 1 : NULL;
    }
    if (ptr) *(ptr - 1) = '\0';
    return str;
}
