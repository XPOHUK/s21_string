#include "s21_string.h"
#include <string.h>  // Удалить при начале разработки эту заглушку

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке,
// на которую указывает аргумент str.
char *s21_strchr(const char *str, int c) {
    return *strchr(*str, c);  // Удалить при начале разработки эту заглушку
}
