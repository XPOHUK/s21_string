#include "s21_string.h"

// Возвращает новую строку, в которой указанная строка (str)
// вставлена в указанную позицию (start_index) в данной строке (src).
// В случае какой-либо ошибки следует вернуть значение NULL
void *s21_insert(const char *src, const char *str, size_t start_index) {
    // При начале разработки содержимое функции, которое ниже
    const char *result = NULL;
    if (start_index > 0 && start_index < s21_strlen(src)) {
        result = src;
    } else if (start_index == 0) {
        result = str;
    }
    return (void *)result;
    // При начале разработки содержимое функции, которое выше
}
