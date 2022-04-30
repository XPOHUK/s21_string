#ifndef SRC_ROMAINEZ_S21_STRING_H_
#define SRC_ROMAINEZ_S21_STRING_H_
#include <stddef.h>

// сравнивает строку str1 со строкой str2
int s21_strcmp(const char *str1, const char *str2);
// сравнивает не более n первых байтов str1 и str2
int s21_strncmp(const char *str1, const char *str2, size_t n);

#endif  // SRC_ROMAINEZ_S21_STRING_H_
