#include <stdio.h>
#include <string.h>

#include "s21_string.h"
#include "test_s21_string.h"

START_TEST(EOF1) {
    char fstr[] = "%d";
    char str[] = "        ";

    int16_t res1 = s21_sscanf(str, fstr, 0);
    int16_t res2 = sscanf(str, fstr, 0);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(EOF2) {
    char fstr[] = "%d ";
    char str[] = "               ";
    int16_t a1 = 0, a2 = 0;

    int16_t res1 = s21_sscanf(str, fstr, &a1);
    int16_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(EOF3) {
    char fstr[] = "%d ";
    char str[] = "  ";
    int16_t a1 = 0, a2 = 0;

    int16_t res1 = s21_sscanf(str, fstr, &a1);
    int16_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

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

START_TEST(only_chars2) {
    char fstr[] = "%c%c%c%c";
    char str[] = "abcd";
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

START_TEST(only_chars3) {
    char fstr[] = "%c %c %c      %c";
    char str[] = "1 a 3   c           ";
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

START_TEST(only_chars4) {
    char fstr[] = "%c %c %c %c";
    char str[] = "   000 0    ";
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

START_TEST(only_chars5) {
    char fstr[] = "%c %c %c %c";
    char str[] = "tttt";
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

START_TEST(special_symbols_as_chars1) {
    char fstr[] = "%c%c%c%c";
    char str[] = "\\\n\t\t\t";
    int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(special_symbols_as_chars2) {
    char fstr[] = "%c %c %c %c";
    char str[] = "z ' ' /";
    int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(special_symbols_as_chars3) {
    char fstr[] = "%c%*c%c%c";
    char str[] = "ABCD";
    int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);

    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
}
END_TEST

Suite *make_sscanf_suite(void) {
    Suite *s = suite_create("Sscanf function tests");
    TCase *tc_eof;
    TCase *tc_only_chars;
    TCase *tc_special_symbols_as_chars;

    tc_eof = tcase_create("EOF");
    tcase_add_test(tc_eof, EOF1);
    tcase_add_test(tc_eof, EOF2);
    tcase_add_test(tc_eof, EOF3);

    suite_add_tcase(s, tc_eof);

    tc_only_chars = tcase_create("only_chars");
    tcase_add_test(tc_only_chars, only_chars1);
    tcase_add_test(tc_only_chars, only_chars2);
    tcase_add_test(tc_only_chars, only_chars3);
    tcase_add_test(tc_only_chars, only_chars4);
    tcase_add_test(tc_only_chars, only_chars5);

    suite_add_tcase(s, tc_only_chars);

    tc_special_symbols_as_chars = tcase_create("special_symbols_as_chars");
    tcase_add_test(tc_special_symbols_as_chars, special_symbols_as_chars1);
    tcase_add_test(tc_special_symbols_as_chars, special_symbols_as_chars2);
    tcase_add_test(tc_special_symbols_as_chars, special_symbols_as_chars3);

    suite_add_tcase(s, tc_special_symbols_as_chars);

    return s;
}
