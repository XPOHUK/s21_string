#include <string.h>  // Удалить при начале разработки эту заглушку

#include "s21_string.h"

// Находит первое вхождение всей строки needle
// (не включая завершающий нулевой символ), которая появляется в строке haystack.
char *s21_strstr(const char *haystack, const char *needle) {
    char *res = NULL;
    while (*haystack != '\0' && s21_strlen(haystack) >= s21_strlen(needle) &&
           s21_strncmp(haystack, needle, s21_strlen(needle))) {
        haystack++;
        // if (*haystack == *needle) {
        //     for (size_t i = 0; i < s21_strlen(needle); i++) {
        //         if (*(haystack + i) == *(needle + i)) {
        //             continue;
        //         } else {
        //             get = 1;
        //             break;
        //         }
        //     }
        //     if (!get) {
        //         res = (char *)haystack;
        //         break;
        //     }
        // }
        // haystack++;
        // get = 0;
    }
    if (s21_strlen(haystack) >= s21_strlen(needle)) res = (char *)haystack;
    return res;
}
