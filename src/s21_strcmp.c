#include "s21_string.h"
#include <string.h>  // Удалить при начале разработки эту заглушку

// Сравнивает строку, на которую указывает str1, со строкой,
// на которую указывает str2.
int s21_strcmp(const char *str1, const char *str2) {
    return strcmp(*str1, *str2);  // Удалить при начале разработки эту заглушку
}

