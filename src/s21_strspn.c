#include "s21_string.h"
#include <string.h>  // Удалить при начале разработки эту заглушку

// Вычисляет длину начального сегмента str1,
// который полностью состоит из символов str2.
size_t s21_strspn(const char *str1, const char *str2) {
    return strspn(*str1, *str2);  // Удалить при начале разработки эту заглушку
}
