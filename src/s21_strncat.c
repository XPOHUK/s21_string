#include "s21_string.h"
#include <string.h>  // Удалить при начале разработки эту заглушку

// Добавляет строку, на которую указывает src, в конец строки,
// на которую указывает dest, длиной до n символов.
char *s21_strncat(char *dest, const char *src, size_t n) {
    return strncat(dest, src, n);  // Удалить при начале разработки эту заглушку
}
