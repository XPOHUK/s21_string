// Copyright [2022] <isleanna>
#include "s21_string.h"

// Вычисляет длину начального сегмента str1,
// который полностью состоит из символов, не входящих в str2.
size_t s21_strcspn(const char *str1, const char *str2) {
    const char *s1;
    const char *s2;
    size_t i;

    i = 0;
    for (s1 = str1; *s1 != '\0'; ++s1) {
        for (s2 = str2; *s2 != '\0'; ++s2) {
        if (*s1 == *s2)
            return (i);
        }
        ++i;
    }
    return (i);
}
