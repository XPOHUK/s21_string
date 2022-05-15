#include "s21_strerror.h"

#include <string.h>
#include <errno.h>
#include <stdio.h>

#include "s21_string.h"

char message[MAX_MESSAGE];

char *s21_strerror(int errnum) {
    if ((errnum >= 0) && (errnum < ERRMAX)) {
        s21_strcpy(message, errors[errnum]);
    } else {
        s21_sprintf(message, "Unknown error: %d", errnum);
    }
    return message;
}
