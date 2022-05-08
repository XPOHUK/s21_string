#include <check.h>
#include <stdio.h>
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
}
END_TEST

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
}
END_TEST

START_TEST(test_memcpy) {
    char *s = "Deadline is approaching!";
    char d[25] = {0};
    char e[25] = {0};
    extern void *s21_memcpy(void *dest, const void *src, size_t n);

    ck_assert_str_eq(s21_memcpy(d, s, 8), memcpy(e, s, 8));
}
END_TEST

START_TEST(test_memmove) {
    char src[15] = "Hello world!";
    char dst1[15] = "";
    char dst2[15] = "";
    int n = 5;
    extern void *s21_memmove(void *dest, const void *src, size_t n);

    ck_assert_str_eq(s21_memmove(dst1, src, n), memmove(dst2, src, n));

    memset(dst1, 0, sizeof(dst1));
    memset(dst2, 0, sizeof(dst2));
    n = 0;
    ck_assert_str_eq(s21_memmove(dst1, src, n), memmove(dst2, src, n));

    memset(dst1, 0, sizeof(dst1));
    memset(dst2, 0, sizeof(dst2));
    n = 0;
    ck_assert_str_eq(s21_memmove(dst1, src, n), memmove(dst2, src, n));
}
END_TEST

START_TEST(test_memset) {
    char array[5] = "ABCD";
    char array2[5] = "ABCD";
    char expected[5] = "000D";
    int n = 3;
    extern void *s21_memset(void *str, int c, size_t n);

    s21_memset(array, '0', n);
    ck_assert_str_eq(expected, array);
    ck_assert_str_eq(array, memset(array2, '0', n));
}
END_TEST

START_TEST(test_strcmp) {
    int result;
    char *str1 = "school21";
    char *str2 = "school21";
    char *str3 = "school42";
    extern int s21_strcmp(const char *str1, const char *str2);

    result = s21_strcmp(str1, str2);
    ck_assert_int_eq(result, 0);
    ck_assert_int_eq(result, strcmp(str1, str2));

    result = s21_strcmp(str1, str3);
    ck_assert_int_lt(result, 0);
    ck_assert(result < 0 && strcmp(str1, str3) < 0);
}
END_TEST

START_TEST(test_strncmp) {
    int result;
    char *str1 = "1234567890";
    char *str2 = "1234507890";
    int n1 = 5;
    int n2 = 6;
    extern int s21_strncmp(const char *str1, const char *str2, size_t n);

    result = s21_strncmp(str1, str2, n1);
    ck_assert_int_eq(result, 0);
    ck_assert_int_eq(result, strncmp(str1, str2, n1));

    result = s21_strncmp(str1, str2, n2);
    ck_assert_int_gt(result, 0);
    ck_assert(result > 0 && strncmp(str1, str2, n2) > 0);
}
END_TEST

START_TEST(test_strcpy) {
    char src[25] = "Hello world!";
    char dest[25] = "";
    char res[25] = {0};
    char expected[25] = "Hello world!";
    extern char *s21_strcpy(char *dest, const char *src);

    s21_strcpy(dest, src);
    ck_assert_str_eq(expected, dest);
    ck_assert_str_eq(dest, strcpy(res, src));
}
END_TEST

START_TEST(test_strncpy) {
    char src[25] = "Hello world!";
    char dest[25] = "";
    char res[25] = {0};
    char expected[25] = "Hello w";
    int n = 7;
    extern char *s21_strncpy(char *dest, const char *src, size_t n);

    s21_strncpy(dest, src, n);
    ck_assert_str_eq(expected, dest);
    ck_assert_str_eq(dest, strncpy(res, src, n));
}
END_TEST

START_TEST(test_strlen) {
    char str[25] = "Hello world!";

    ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strcspn) {
    char str[25] = "Hello world!";
    char rej[5] = "ab cd";

    ck_assert_int_eq(s21_strcspn(str, rej), strcspn(str, rej));
}
END_TEST

START_TEST(test_insert) {
    char string[41] = "Error. Press F1 to continue";
    char to_insert[20] = "No keyboard. ";
    char expected[100] = "Error. No keyboard. Press F1 to continue";

    ck_assert_str_eq(expected, s21_insert(string, to_insert, 7));
}
END_TEST

START_TEST(test_strpbrk) {
    char string[] = "Functions that will make our lives easier!";
    char chars[] = "rsaf";

    ck_assert_str_eq(s21_strpbrk(string, chars), strpbrk(string, chars));
}
END_TEST

START_TEST(test_strrchr) {
    char *string = "Snickersnee";
    char search_for = 'n';

    ck_assert_str_eq(s21_strrchr(string, search_for), strrchr(string, search_for));
}
END_TEST

START_TEST(test_sprintf) {
    char orig[100] = {0};
    char res[100] = {0};
    extern int s21_sprintf(char *str, const char *format, ...);

    s21_sprintf(res, "%d %-d %+d % d", 123, 123, 123, 123);
    sprintf(orig, "%d %-d %+d % d", 123, 123, 123, 123);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%5d %-5d %+5d % 5d", 123, 123, 123, 123);
    sprintf(orig, "%5d %-5d %+5d % 5d", 123, 123, 123, 123);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%5.2d %-5.2d %+5.2d % 5.2d", 123, 123, 123, 123);
    sprintf(orig, "%5.2d %-5.2d %+5.2d % 5.2d", 123, 123, 123, 123);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%5.2d %-5.2d %+5.2d % 5.2d", -123, -123, -123, -123);
    sprintf(orig, "%5.2d %-5.2d %+5.2d % 5.2d", -123, -123, -123, -123);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%5.2ld %-5.2ld %+5.2ld % 5.2ld", (long int)123, (long int)123, (long int)123, (long int)123);
    sprintf(orig, "%5.2ld %-5.2ld %+5.2ld % 5.2ld", (long int)123, (long int)123, (long int)123, (long int)123);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%5.2hd %-5.2hd %+5.2hd % 5.2hd", (short int)123, (short int)123, (short int)123, (short int)123);
    sprintf(orig, "%5.2hd %-5.2hd %+5.2hd % 5.2hd", (short int)123, (short int)123, (short int)123, (short int)123);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%f %-f %+f % f", 1.123f, 1.123f, 1.123f, 1.123f);
    sprintf(orig, "%f %-f %+f % f", 1.123f, 1.123f, 1.123f, 1.123f);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%10f %-10f %+10f % 10f", 1.123f, 1.123f, 1.123f, 1.123f);
    sprintf(orig, "%10f %-10f %+10f % 10f", 1.123f, 1.123f, 1.123f, 1.123f);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%10f %-10.f %+10.2f % 10.0f", 1.123f, 1.123f, 1.125f, 1.123f);
    sprintf(orig, "%10f %-10.f %+10.2f % 10.0f", 1.123f, 1.123f, 1.125f, 1.123f);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%10f %-10.f %+10.2f % 10.0f", -1.123f, -1.123f, -1.125f, -1.123f);
    sprintf(orig, "%10f %-10.f %+10.2f % 10.0f", -1.123f, -1.123f, -1.125f, -1.123f);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%10s %-10.s %10.2s %10.0s", "-1.123f", "-1.123f", "-1.125f", "-1.123f");
    sprintf(orig, "%10s %-10.s %10.2s %10.0s", "-1.123f", "-1.123f", "-1.125f", "-1.123f");
    ck_assert_str_eq(res, orig);
}
END_TEST

Suite *test_suite(void) {
    Suite *s;
    TCase *tc_memchr;
    TCase *tc_memcmp;
    TCase *tc_memcpy;
    TCase *tc_memmove;
    TCase *tc_memset;
    TCase *tc_strcmp;
    TCase *tc_strncmp;
    TCase *tc_strcpy;
    TCase *tc_strncpy;
    TCase *tc_strlen;
    TCase *tc_strcspn;
    TCase *tc_insert;
    TCase *tc_strpbrk;
    TCase *tc_strrchr;
    TCase *tc_sprintf;

    s = suite_create("String lib tests");

    tc_memchr = tcase_create("memchr");
    tcase_add_test(tc_memchr, test_memchr);
    suite_add_tcase(s, tc_memchr);

    tc_memcmp = tcase_create("memcmp");
    tcase_add_test(tc_memcmp, test_memcmp);
    suite_add_tcase(s, tc_memcmp);

    tc_memcpy = tcase_create("memcpy");
    tcase_add_test(tc_memcpy, test_memcpy);
    suite_add_tcase(s, tc_memcpy);

    tc_memmove = tcase_create("memmove");
    tcase_add_test(tc_memmove, test_memmove);
    suite_add_tcase(s, tc_memmove);

    tc_memset = tcase_create("memset");
    tcase_add_test(tc_memset, test_memset);
    suite_add_tcase(s, tc_memset);

    tc_strcmp = tcase_create("strcmp");
    tcase_add_test(tc_strcmp, test_strcmp);
    suite_add_tcase(s, tc_strcmp);

    tc_strncmp = tcase_create("strncmp");
    tcase_add_test(tc_strncmp, test_strncmp);
    suite_add_tcase(s, tc_strncmp);

    tc_strcpy = tcase_create("Strcpy");
    tcase_add_test(tc_strcpy, test_strcpy);
    suite_add_tcase(s, tc_strcpy);

    tc_strncpy = tcase_create("Strncpy");
    tcase_add_test(tc_strncpy, test_strncpy);
    suite_add_tcase(s, tc_strncpy);

    tc_strlen = tcase_create("strlen");
    tcase_add_test(tc_strlen, test_strlen);
    suite_add_tcase(s, tc_strlen);

    tc_strcspn = tcase_create("strcspn");
    tcase_add_test(tc_strcspn, test_strcspn);
    suite_add_tcase(s, tc_strcspn);

    tc_insert = tcase_create("insert");
    tcase_add_test(tc_insert, test_insert);
    suite_add_tcase(s, tc_insert);

    tc_strpbrk = tcase_create("strpbrk");
    tcase_add_test(tc_strpbrk, test_strpbrk);
    suite_add_tcase(s, tc_strpbrk);

    tc_strrchr = tcase_create("strrchr");
    tcase_add_test(tc_strrchr, test_strrchr);
    suite_add_tcase(s, tc_strrchr);

    tc_sprintf = tcase_create("sprintf");
    tcase_add_test(tc_sprintf, test_sprintf);
    suite_add_tcase(s, tc_sprintf);

    return s;
}

int main(void) {
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = test_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);  // CK_SILENT CK_MINIMAL CK_NORMAL CK_VERBOSE
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
