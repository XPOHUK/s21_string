#include "s21_strerror.h"
#include "s21_string.h"

char message[MAX_MESSAGE];

char *s21_strerror(int errnum) {
    if ((errnum >= 0) && (errnum < ERRMAX - 1)) {
        s21_strcpy(message, errors[errnum]);
    } else {
        s21_sprintf(message, "%s %d", errors[134], errnum);
    }
    return message;
}
