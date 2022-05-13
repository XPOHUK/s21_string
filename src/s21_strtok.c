#include <stdio.h>  // Удалить при начале разработки эту заглушку

#include "s21_string.h"

// Разбивает строку str на ряд токенов, разделенных delim.

char *ptr;

char *s21_strtok(char *str, const char *delim) {
    if (str) {
        ptr = str;
    } else {
        str = ptr;
    }
    while (str != NULL && *str != '\0' && s21_strchr(delim, *str)) {
        str++;
    }
    if (str != NULL && s21_strpbrk(str, delim)) {
        char *del = s21_strpbrk(str, delim);
        *del = '\0';
        if (*(del + 1) != '\0') {
            ptr = del + 1;
        } else {
            ptr = NULL;
        }
    } else {
        ptr = NULL;
    }
    return str;
}
//     while (s21_strchr(delim, *str)) str++;
//     if (ptr = s21_strpbrk(str, delim)) {
//         ptr = s21_strpbrk(str, delim) + 1;

//         while (s21_strchr(delim, *ptr)) ptr++;

//     } else if (ptr) {
//         str = ptr;
//         if (s21_strpbrk(str, delim)) {
//             ptr = s21_strpbrk(str, delim) + 1;
//             *s21_strpbrk(str, delim) = '\0';
//             while (s21_strchr(delim, *ptr)) ptr++;
//         }
//     }

//     return str;
// }
