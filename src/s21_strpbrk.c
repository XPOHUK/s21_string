#include "s21_string.h"
#include <string.h>  // Удалить при начале разработки эту заглушку

// Находит первый символ в строке str1, который соответствует любому символу,
// указанному в str2.
char *s21_strpbrk(const char *str1, const char *str2) {
    return *strpbrk(*str1, *str2);  // Удалить при начале разработки эту заглушку
}
