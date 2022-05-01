#include "s21_string.h"
#include <string.h>  // Удалить при начале разработки эту заглушку

// Еще одна функция для копирования n символов из str2 в str1.
void *s21_memmove(void *dest, const void *src, size_t n) {
<<<<<<< HEAD
    *memmove(*dest, *src, n);  // Удалить при начале разработки эту заглушку
}
=======
    char *d;
    const char *s;
    size_t i;

    d = (char *)dest;
    s = (const char *)src;
    i = 0;
    if (d == s) {
        return (dest);
    }
    if (d < s) {
        while (i < n) {
            ((char *)d)[i] = ((const char *)s)[i];
            i++;
        }
    } else if (d > s) {
        while (n > 0) {
            n--;
            ((char *)d)[n] = ((const char *)s)[n];
        }
    }
    return (dest);
}

//// Тест функции
//int main() {
//    char str[42] = "I am relocating from California to Texas.";
//    printf("Original:\t%s\n", str);
//    printf("Source:\t\t%s\n", str + 5);
//    printf("Destination:\t%s\n", str + 16);
//    s21_memmove(str + 16, str + 5, 37);
//    printf("Result:\t\t%s\n", str);
//    return 0;
//}
>>>>>>> 09d9fb4 (Fix merge & working Makefile)
