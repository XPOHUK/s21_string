#include "s21_string.h"
#include <string.h>  // Удалить при начале разработки эту заглушку

// Копирует до n символов из строки, на которую указывает src, в dest.
char *s21_strncpy(char *dest, const char *src, size_t n) {
    return *strncpy(*dest, *src, n);  // Удалить при начале разработки эту заглушку
}
