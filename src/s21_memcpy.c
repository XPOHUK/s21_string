#include "s21_string.h"
#include <string.h>  // Удалить при начале разработки эту заглушку

// Копирует n символов из src в dest.
void *s21_memcpy(void *dest, const void *src, size_t n) {
    *memcpy(*dest, *src, n);  // Удалить при начале разработки эту заглушку
}
