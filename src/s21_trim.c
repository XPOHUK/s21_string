// Copyright [2022] <isleanna>

#include "s21_string.h"

// Возвращает новую строку, в которой удаляются все начальные и конечные
// вхождения набора заданных символов (trim_chars) из данной строки (src).
// В случае какой-либо ошибки следует вернуть значение NULL
void *s21_trim(const char *src, const char *trim_chars) {
    s21_size_t lead = 0;
    s21_size_t trail = s21_strlen(src);
    char *res = NULL;
    s21_size_t i = 0;
    while (src[lead] && s21_strchr(trim_chars, src[lead])) {
        lead++;
    }
    while (trail > lead && s21_strchr(trim_chars, src[trail - 1])) {
        trail--;
    }
    res = malloc(sizeof(char) * (trail - lead + 1));
    if (res) {
        while (lead < trail) {
            res[i++] = src[lead++];
        }
        res[i] = '\0';
    }
    return (res);
}
