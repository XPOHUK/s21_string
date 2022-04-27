#include "s21_string.h"
#include <string.h>  // Удалить при начале разработки эту заглушку

// Считывает форматированный ввод из строки.
int s21_sscanf(const char *str, const char *format, ...) {
    return sscanf(*str, *format, ...);  // Удалить при начале разработки эту заглушку
}
