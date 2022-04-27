#include "s21_string.h"
#include <string.h>  // Удалить при начале разработки эту заглушку

// Еще одна функция для копирования n символов из str2 в str1.
void *s21_memmove(void *dest, const void *src, size_t n) {
    *memmove(*dest, *src, n);  // Удалить при начале разработки эту заглушку
}
