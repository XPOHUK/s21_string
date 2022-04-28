#include "s21_string.h"
#include <string.h>  // Удалить при начале разработки эту заглушку

// Выполняет поиск во внутреннем массиве номера ошибки errnum
// и возвращает указатель на строку с сообщением об ошибке.
// Нужно объявить макросы, содержащие массивы сообщений об ошибке
// для операционных систем mac и linux.
// Описания ошибок есть в оригинальной библиотеке.
// Проверка текущей ОС осуществляется с помощью директив.
char *s21_strerror(int errnum) {
    return strerror(errnum);  // Удалить при начале разработки эту заглушку
}