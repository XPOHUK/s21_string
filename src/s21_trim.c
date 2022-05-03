#include "s21_string.h"

// Возвращает новую строку, в которой удаляются все начальные и конечные
// вхождения набора заданных символов (trim_chars) из данной строки (src).
// В случае какой-либо ошибки следует вернуть значение NULL
void *s21_trim(const char *src, const char *trim_chars) {
    // При начале разработки содержимое функции, которое ниже
    const char *result = NULL;
    if (s21_strlen(src) > 0 && s21_strlen(trim_chars) > 0) {
        result = src;
    }
    return (void *)result;
    // При начале разработки содержимое функции, которое выше
}
