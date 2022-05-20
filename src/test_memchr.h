#ifndef SRC_TEST_MEMCHR_H_
#define SRC_TEST_MEMCHR_H_

START_TEST(test_memchr) {
    char *str = "21school";
    char *to_find = "sSx h70";

    while (*to_find) {
        ck_assert_pstr_eq(s21_memchr(str, *to_find, s21_strlen(str) + 1),
                          memchr(str, *to_find, s21_strlen(str) + 1));
        to_find++;
    }
    ck_assert_pstr_eq(s21_memchr(str, *to_find, s21_strlen(str) + 1),
                      memchr(str, *to_find, s21_strlen(str) + 1));

    ck_assert_pstr_eq(s21_memchr(str, 'o', 3), memchr(str, 'o', 3));

    char *str2 = " ";
    char *to_find2 = "";
    ck_assert_pstr_eq(s21_memchr(str2, *to_find2, 1), memchr(str2, *to_find2, 1));

    // Наша функция защищена от n большего, чем длина строки
    ck_assert_pstr_eq(s21_memchr(str2, *to_find2, 3), memchr(str2, *to_find2, 2));
    // Наша функция защищена от нулевого указателя вместо строки
    ck_assert_ptr_null(s21_memchr(S21_NULL, 'x', 10));
}
END_TEST

#endif  // SRC_TEST_MEMCHR_H_