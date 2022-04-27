#include "s21_string.h"
#include <string.h>  // Удалить при начале разработки эту заглушку

// Разбивает строку str на ряд токенов, разделенных delim.
char *s21_strtok(char *str, const char *delim) {
    return *strtok(*str, *delim);  // Удалить при начале разработки эту заглушку
}
