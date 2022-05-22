#include <stdio.h>
#include <string.h>

#include "s21_string.h"
#include "test_s21_string.h"

START_TEST(only_chars1) {
    char fstr[] = "%c %c %c %c";
    char str[] = "   a     b c d";
    int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

Suite *make_sscanf_suite(void) {
    Suite *s = suite_create("Sscanf function tests");
    TCase *tc_sscanf;

    tc_sscanf = tcase_create("sscanf");
    tcase_add_test(tc_sscanf, only_chars1);

    suite_add_tcase(s, tc_sscanf);

    return s;
}