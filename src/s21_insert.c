// Copyright [2022] <isleanna>
#include "s21_string.h"

// Возвращает новую строку, в которой указанная строка (str)
// вставлена в указанную позицию (start_index) в данной строке (src).
// В случае какой-либо ошибки следует вернуть значение NULL
void *s21_insert(const char *src, const char *str, size_t start_index) {
    char *src2 = (char *)src;
    size_t srcl = s21_strlen(src2);
    size_t strl = s21_strlen(str);
    if (srcl < start_index) {
        start_index = srcl;
    }
    for (size_t i = 0; i < srcl - start_index; i++) {
        src2[srcl + strl - i - 1] = src2[srcl - i - 1];
    }
    for (size_t i = 0; i < strl; i++) {
        src2[start_index + i] = str[i];
    }
    return (src2);

    const char *result = NULL;
    if (start_index > 0 && start_index < s21_strlen(src)) {
        result = src;
    } else if (start_index == 0) {
        result = str;
    }
    return (void *)result;
}
