#include "s21_string.h"
#include "s21_error_lib.h"
#include <string.h>
#include <errno.h>
#include <stdio.h>

// Выполняет поиск во внутреннем массиве номера ошибки errnum
// и возвращает указатель на строку с сообщением об ошибке.
// Нужно объявить макросы, содержащие массивы сообщений об ошибке
// для операционных систем mac и linux.
// Описания ошибок есть в оригинальной библиотеке.
// Проверка текущей ОС осуществляется с помощью директив.

char message[200];

char *s21_strerror(int errnum) {
    if ((errnum > 0) && (errnum <= ERRMAX)) {
        s21_sprintf(message, errors[errnum]);
    } else {
        s21_sprintf(message, "Unknown error: %d", errnum);
    }
    return message;
}


int main() {
    FILE *fp;
    errno = 0;
    fp = fopen("file", "r");
    if (fp != NULL) {
        printf(strerror(errno));
     }
    fclose(fp);
}
