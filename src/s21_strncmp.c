#include "s21_string.h"
#include <string.h>  // Удалить при начале разработки эту заглушку

// Сравнивает не более первых n байтов str1 и str2.
int s21_strncmp(const char *str1, const char *str2, size_t n) {
    return strncmp(str1, str2, n);  // Удалить при начале разработки эту заглушку
}
