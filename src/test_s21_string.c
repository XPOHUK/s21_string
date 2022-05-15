#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

#include "s21_string.h"

START_TEST(test_memchr) {
    char *ch;
    char *s = "21school";
    extern void *s21_memchr(const void *str, int c, s21_size_t n);

    ch = s21_memchr(s, 's', strlen(s));
    ck_assert_str_eq(ch, "school");
    ck_assert_str_eq(ch, memchr(s, 's', 8));
    ch = s21_memchr(s, 'k', 10);
    ck_assert_pstr_eq(ch, NULL);
    ck_assert_pstr_eq(ch, memchr(s, 'k', 9));
    // ck_assert_pstr_eq(s21_memchr(NULL, 'k', 10), memchr(NULL, 'k', 10));
}
END_TEST

START_TEST(test_memcmp) {
    int result;
    char *str1 = "21school";
    char *str2 = "21school";
    char *str3 = "42school";
    extern int s21_memcmp(const void *str1, const void *str2, s21_size_t n);

    result = s21_memcmp(str1, str2, strlen(str1));
    ck_assert_int_eq(result, 0);
    ck_assert_int_eq(result, memcmp(str1, str2, 8));
    result = s21_memcmp(str1, str3, strlen(str1));
    ck_assert_int_lt(result, 0);
    ck_assert(result < 0 && memcmp(str1, str3, 8) < 0);
    result = s21_memcmp(str3, str1, strlen(str1));
    ck_assert_int_gt(result, 0);
    ck_assert(result > 0 && memcmp(str3, str1, 8) > 0);
    result = s21_memcmp(str1, str3, 0);
    ck_assert_int_eq(result, 0);
    ck_assert_int_eq(result, memcmp(str1, str3, 0));
}
END_TEST

START_TEST(test_memcpy) {
    char *s = "Deadline is approaching!";
    char d[25] = {0};
    char e[25] = {0};
    extern void *s21_memcpy(void *dest, const void *src, s21_size_t n);

    ck_assert_str_eq(s21_memcpy(d, s, 8), memcpy(e, s, 8));
}
END_TEST

START_TEST(test_memmove) {
    char src[15] = "Hello world!";
    char dst1[15] = "";
    char dst2[15] = "";
    int n = 5;
    extern void *s21_memmove(void *dest, const void *src, s21_size_t n);

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
    extern void *s21_memset(void *str, int c, s21_size_t n);

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
    extern int s21_strncmp(const char *str1, const char *str2, s21_size_t n);

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
    extern char *s21_strncpy(char *dest, const char *src, s21_size_t n);

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
    char empty[] = "";

    ck_assert_int_eq(s21_strcspn(str, rej), strcspn(str, rej));
    ck_assert_int_eq(s21_strcspn(empty, rej), strcspn(empty, rej));
    ck_assert_int_eq(s21_strcspn(str, empty), strcspn(str, empty));
}
END_TEST

START_TEST(test_strspn) {
    char str[25] = "Hello world!";
    char acc[5] = "eollH";
    char empty[] = "";

    ck_assert_int_eq(s21_strspn(str, acc), strspn(str, acc));
    ck_assert_int_eq(s21_strspn(empty, acc), strspn(empty, acc));
    ck_assert_int_eq(s21_strspn(str, empty), strspn(str, empty));
}
END_TEST

START_TEST(test_insert) {
    char string[41] = "Error. Press F1 to continue";
    char to_insert[20] = "No keyboard. ";
    char expected[100] = "Error. No keyboard. Press F1 to continue";

    char *res = s21_insert(string, to_insert, 7);
    ck_assert_str_eq(expected, res);
    if (res) free(res);
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

START_TEST(test_strchr) {
    char *string = "Snickersnee";
    char search_for = 'n';

    ck_assert_str_eq(s21_strchr(string, search_for), strchr(string, search_for));
}
END_TEST

START_TEST(test_to_upper) {
    char str[] = "this is sparta!";
    char *expected = "THIS IS SPARTA!";
    char str2[] = "";

    char *res1 = s21_to_upper(str);
    char *res2 = s21_to_upper(str2);
    ck_assert_pstr_eq(res1, expected);
    ck_assert_pstr_eq(res2, "");
    if (res1) free(res1);
    if (res2) free(res2);
}
END_TEST

START_TEST(test_to_lower) {
    char str[] = "THIS IS SPARTA!";
    char *expected = "this is sparta!";
    char str2[] = "";

    char *res1 = s21_to_lower(str);
    char *res2 = s21_to_lower(str2);
    ck_assert_pstr_eq(res1, expected);
    ck_assert_pstr_eq(res2, "");
    if (res1) free(res1);
    if (res2) free(res2);
}
END_TEST

START_TEST(test_strstr) {
    char *haystack = "This is Sparta!";
    char *haystack2 = "";
    char *needle = "is S";
    char *needle2 = "is S";

    ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
    ck_assert_pstr_eq(s21_strstr(haystack, needle2), strstr(haystack, needle2));
    ck_assert_pstr_eq(s21_strstr(haystack2, needle), strstr(haystack2, needle));
}
END_TEST

START_TEST(test_strcat) {
    char dst[100] = "Hello";
    char dst2[100] = "Hello";
    char *src = " World!";

    ck_assert_str_eq(s21_strcat(dst, src), strcat(dst2, src));
}
END_TEST

START_TEST(test_strncat) {
    char dst[100] = "Hello";
    char dst2[100] = "Hello";
    char *src = " World!";

    ck_assert_str_eq(s21_strncat(dst, src, 3), strncat(dst2, src, 3));
}
END_TEST

START_TEST(test_strtok) {
    char p[15] = "VK is Bad Guy";
    char exp[15] = "VK is Bad Guy";
    char *delim = "Visay";

    ck_assert_pstr_eq(s21_strtok(p, delim), strtok(exp, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
}
END_TEST

START_TEST(test_strerror) {
    int errno = 0;
    int ERRMAX = 150;
    while (errno < ERRMAX) {
        ck_assert_str_eq(strerror(errno), s21_strerror(errno));
        errno++;
    }
}
END_TEST

START_TEST(test_trim) {
    char string[] = "./Nincompooper";
    char trim_chars[] = "re/.";

    char *res = s21_trim(string, trim_chars);
    ck_assert_str_eq(res, "Nincompoop");
    if (res) free(res);
}

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
    s21_sprintf(res, "%5.2ld %-5.2ld %+5.2ld % 5.2ld", (long int)123, (long int)123, (long int)123,
                (long int)123);
    sprintf(orig, "%5.2ld %-5.2ld %+5.2ld % 5.2ld", (long int)123, (long int)123, (long int)123,
            (long int)123);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%5.2hd %-5.2hd %+5.2hd % 5.2hd", (short int)123, (short int)123, (short int)123,
                (short int)123);
    sprintf(orig, "%5.2hd %-5.2hd %+5.2hd % 5.2hd", (short int)123, (short int)123, (short int)123,
            (short int)123);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%% %5.2u %-5.2u %%", 123, 123);
    sprintf(orig, "%% %5.2u %-5.2u %%", 123, 123);
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
    s21_sprintf(res, "%10f %-10.f %+10.2f % 10.0f", 1.123f, 1.523f, 1.125f, 1.123f);
    sprintf(orig, "%10f %-10.f %+10.2f % 10.0f", 1.123f, 1.523f, 1.125f, 1.123f);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%10f %-10.f %+10.2f % 10.0f", -1.123f, -2.123f, -1.125f, -1.123f);
    sprintf(orig, "%10f %-10.f %+10.2f % 10.0f", -1.123f, -2.123f, -1.125f, -1.123f);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%10s %-10.s %10.2s %10.0s", "-1.123f", "-1.123f", "-1.125f", "-1.123f");
    sprintf(orig, "%10s %-10.s %10.2s %10.0s", "-1.123f", "-1.123f", "-1.125f", "-1.123f");
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%c %-c", 'a', 'b');
    sprintf(orig, "%c %-c", 'a', 'b');
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%5c %-5c %-5lc", 'a', 'b', L'c');
    sprintf(orig, "%5c %-5c %-5lc", 'a', 'b', L'c');
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "Test string");
    sprintf(orig, "Test string");
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
    TCase *tc_strspn;
    TCase *tc_insert;
    TCase *tc_strpbrk;
    TCase *tc_strrchr;
    TCase *tc_strchr;
    TCase *tc_to_upper;
    TCase *tc_to_lower;
    TCase *tc_strstr;
    TCase *tc_strcat;
    TCase *tc_strncat;
    TCase *tc_strtok;
    TCase *tc_trim;
    TCase *tc_strerror;
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

    tc_strcpy = tcase_create("strcpy");
    tcase_add_test(tc_strcpy, test_strcpy);
    suite_add_tcase(s, tc_strcpy);

    tc_strncpy = tcase_create("strncpy");
    tcase_add_test(tc_strncpy, test_strncpy);
    suite_add_tcase(s, tc_strncpy);

    tc_strlen = tcase_create("strlen");
    tcase_add_test(tc_strlen, test_strlen);
    suite_add_tcase(s, tc_strlen);

    tc_strcspn = tcase_create("strcspn");
    tcase_add_test(tc_strcspn, test_strcspn);
    suite_add_tcase(s, tc_strcspn);

    tc_strspn = tcase_create("strspn");
    tcase_add_test(tc_strspn, test_strspn);
    suite_add_tcase(s, tc_strspn);

    tc_insert = tcase_create("insert");
    tcase_add_test(tc_insert, test_insert);
    suite_add_tcase(s, tc_insert);

    tc_strpbrk = tcase_create("strpbrk");
    tcase_add_test(tc_strpbrk, test_strpbrk);
    suite_add_tcase(s, tc_strpbrk);

    tc_strrchr = tcase_create("strrchr");
    tcase_add_test(tc_strrchr, test_strrchr);
    suite_add_tcase(s, tc_strrchr);

    tc_strchr = tcase_create("strchr");
    tcase_add_test(tc_strchr, test_strchr);
    suite_add_tcase(s, tc_strchr);

    tc_to_upper = tcase_create("to_upper");
    tcase_add_test(tc_to_upper, test_to_upper);
    suite_add_tcase(s, tc_to_upper);

    tc_to_lower = tcase_create("to_lower");
    tcase_add_test(tc_to_lower, test_to_lower);
    suite_add_tcase(s, tc_to_lower);

    tc_strstr = tcase_create("strstr");
    tcase_add_test(tc_strstr, test_strstr);
    suite_add_tcase(s, tc_strstr);

    tc_strcat = tcase_create("strcat");
    tcase_add_test(tc_strcat, test_strcat);
    suite_add_tcase(s, tc_strcat);

    tc_strncat = tcase_create("strncat");
    tcase_add_test(tc_strncat, test_strncat);
    suite_add_tcase(s, tc_strncat);

    tc_strtok = tcase_create("strtok");
    tcase_add_test(tc_strtok, test_strtok);
    suite_add_tcase(s, tc_strtok);

    tc_strerror = tcase_create("strerror");
    tcase_add_test(tc_strerror, test_strerror);
    suite_add_tcase(s, tc_strerror);

    tc_trim = tcase_create("trim");
    tcase_add_test(tc_trim, test_trim);
    suite_add_tcase(s, tc_trim);

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

    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_VERBOSE);  // CK_SILENT CK_MINIMAL CK_NORMAL CK_VERBOSE
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
