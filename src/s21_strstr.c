#include "s21_string.h"
#include <string.h>  // Удалить при начале разработки эту заглушку

// Находит первое вхождение всей строки needle
// (не включая завершающий нулевой символ), которая появляется в строке haystack.
char *s21_strstr(const char *haystack, const char *needle) {
    return *strstr(*haystack, *needle);  // Удалить при начале разработки эту заглушку
}
