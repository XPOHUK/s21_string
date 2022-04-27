#include "s21_string.h"
#include <string.h>  // Удалить при начале разработки эту заглушку

// Возвращает новую строку, в которой удаляются все начальные и конечные
// вхождения набора заданных символов (trim_chars) из данной строки (src).
// В случае какой-либо ошибки следует вернуть значение NULL
void *s21_trim(const char *src, const char *trim_chars) {
    *trim(*src, *trim_chars);  // Удалить при начале разработки эту заглушку
}
