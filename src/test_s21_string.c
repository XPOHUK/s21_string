#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_memchr) {
    char *ch;
    char *s = "21school";
    extern void *s21_memchr(const void *str, int c, size_t n);

    ch = s21_memchr(s, 's', sizeof(s));
    ck_assert_str_eq(ch, "school");
    ck_assert_str_eq(ch, memchr(s, 's', 8));
    ch = s21_memchr(s, 'k', sizeof(s));
    ck_assert_pstr_eq(ch, NULL);
    ck_assert_pstr_eq(ch, memchr(s, 'k', 8));
} END_TEST

START_TEST(test_memcmp) {
    int result;
    char *str1 = "21school";
    char *str2 = "21school";
    char *str3 = "42school";
    extern int s21_memcmp(const void *str1, const void *str2, size_t n);

    result = s21_memcmp(str1, str2, sizeof(str1));
    ck_assert_int_eq(result, 0);
    ck_assert_int_eq(result, memcmp(str1, str2, 8));
    result = s21_memcmp(str1, str3, sizeof(str1));
    ck_assert_int_lt(result, 0);
    ck_assert(result < 0 && memcmp(str1, str3, 8) < 0);
    result = s21_memcmp(str3, str1, sizeof(str1));
    ck_assert_int_gt(result, 0);
    ck_assert(result > 0 && memcmp(str3, str1, 8) > 0);
} END_TEST

START_TEST(test_memcpy) {
    char *s = "Deadline is approaching!";
    char d[25] = {0};
    extern void* s21_memcpy(void *dest, const void *src, size_t n);

    ck_assert_str_eq(s21_memcpy(d, s, 8), memcpy(d, s, 8));
} END_TEST

Suite *memchr_suite(void) {
    Suite *s;
    TCase *tc_memchr;
    TCase *tc_memcmp;
    TCase *tc_memcpy;

    s = suite_create("String lib tests");

    tc_memchr = tcase_create("Memchr");
    tcase_add_test(tc_memchr, test_memchr);
    suite_add_tcase(s, tc_memchr);

    tc_memcmp = tcase_create("Memcmp");
    tcase_add_test(tc_memcmp, test_memcmp);
    suite_add_tcase(s, tc_memcmp);

    tc_memcpy = tcase_create("Memcpy");
    tcase_add_test(tc_memcpy, test_memcpy);
    suite_add_tcase(s, tc_memcpy);

    return s;
}

int main(void) {
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = memchr_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE); // CK_SILENT CK_MINIMAL CK_NORMAL CK_VERBOSE
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
