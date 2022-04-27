#include "s21_string.h"
#include <string.h>  // Удалить при начале разработки эту заглушку

// Сравнивает первые n байтов str1 и str2.
int s21_memcmp(const void *str1, const void *str2, size_t n) {
    return memcmp(*str1, *str2, n);  // Удалить при начале разработки эту заглушку
}
