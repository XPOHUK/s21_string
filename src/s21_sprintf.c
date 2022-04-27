#include "s21_string.h"
#include <string.h>  // Удалить при начале разработки эту заглушку

// Отправляет форматированный вывод в строку, на которую указывает str.
int s21_sprintf(char *str, const char *format, ...) {
    return sprintf(*str, *format, ...);  // Удалить при начале разработки эту заглушку
}
