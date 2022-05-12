#include "s21_string.h"
#include "s21_error_lib.h"
#include <string.h>
#include <errno.h>
#include <stdio.h>

char message[200];

char *s21_strerror(int errnum) {
    if ((errnum > 0) && (errnum <= ERRMAX)) {
       printf(message, errors[errnum]);
       } else {
        printf(message, "Unknown error: %d", errnum);
      }
    return message;
}


int main() {
    FILE *fp;
    errno = 0;
    fp = fopen("file", "r");
    if (fp != NULL) {
        printf("%s", strerror(errno));
     }
    fclose(fp);
}
