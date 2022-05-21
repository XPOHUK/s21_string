#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"
#include "test_memchr.h"

#define compare_print_func(f1, str_sprintf, f2, str_csprintf, fmt, ...) \
    str_sprintf[0] = 0;                                                 \
    str_csprintf[0] = 0;                                                \
    f1(str_sprintf, fmt, __VA_ARGS__);                                  \
    f2(str_csprintf, fmt, __VA_ARGS__);                                 \
    ck_assert_str_eq(str_sprintf, str_csprintf);

START_TEST(test_integer) {
    char str_sprintf[512];
    char str_csprintf[512];
    // INTEGERS
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %d", 7);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "%d:%d:%d", 7, 4, 0);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "MAX %d", INT_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "MIN %d", INT_MIN);
    // %i
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %i", 3534555);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %+d", 3534555);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5d'", 7);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5d'", INT_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5d'", INT_MIN);

    // compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%05d'", 7);
    // compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%05d'", INT_MAX);
    // compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%05d'", INT_MIN);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5d'", 7);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5d'", INT_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5d'", INT_MIN);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5d'", 7);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5d'", INT_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5d'", INT_MIN);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%3.5d'", 7);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%3.5d'", INT_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%3.5d'", INT_MIN);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%-3.5d'", 7);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%-3.5d'", INT_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%-3.5d'", INT_MIN);

    // Unsigned integers
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %u", 7u);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "%u:%u:%u", 7u, 4u, 0u);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "MAX %u", UINT_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "MIN %u", 0u);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5u'", 7u);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5u'", UINT_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5u'", 0u);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5u'", 7u);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5u'", UINT_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5u'", 0u);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5u'", 7u);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5u'", UINT_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5u'", 0u);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%3.5u'", 7u);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%3.5u'", UINT_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%3.5u'", 0u);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%-3.5u'", 7u);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%-3.5u'", UINT_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%-3.5u'", 0u);
}
END_TEST

START_TEST(test_long) {
    char str_sprintf[512];
    char str_csprintf[512];
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %ld", 3534535547l);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "%ld:%ld:%ld", 7l, 34543245324l, 0l);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "%ld", -5435432542l);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "MAX %ld", LONG_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "MIN %ld", LONG_MIN);
    // %i
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %li", 3534535547l);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5ld'", 72341l);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5ld'", LONG_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5ld'", LONG_MIN);

    // compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%05ld'", 72342l);
    // compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%05ld'", LONG_MAX);
    // compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%05ld'", LONG_MIN);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5ld'", 742343l);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5ld'", LONG_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5ld'", LONG_MIN);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5ld'", 754354l);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5ld'", LONG_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5ld'", LONG_MIN);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%3.5ld'", 7343l);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%3.5ld'", LONG_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%3.5ld'", LONG_MIN);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%-3.5ld'", 754354l);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%-3.5ld'", LONG_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%-3.5ld'", LONG_MIN);

    // Unsigned integers
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %lu", 7ul);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "%lu:%lu:%lu", 7ul, 4ul, 0ul);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "MAX %lu", ULONG_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "MIN %lu", 0ul);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5lu'", 7ul);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5lu'", ULONG_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5lu'", 0ul);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5lu'", 7ul);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5lu'", ULONG_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5lu'", 0ul);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5lu'", 7ul);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5lu'", ULONG_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5lu'", 0ul);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%3.5lu'", 7ul);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%3.5lu'", ULONG_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%3.5lu'", 0ul);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%-3.5lu'", 7ul);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%-3.5lu'", ULONG_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%-3.5lu'", 0ul);

    // const char * NULL_STR = NULL;
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %s", "Mundo");
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "%s:%s:%s", "Mi Mundo", "es", "asin");
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Nothing '%s'", "");
    // compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "NULL '%s'", NULL_STR);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5s'", "bar");
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5s'", "barfoobar");
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5s'", "bar");
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5s'", "barfoobar");

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5s'", "bar");
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5s'", "barfoobar");
}
END_TEST

START_TEST(test_padding) {
    char str_sprintf[512];
    char str_csprintf[512];
    // compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %08d", 34);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %8d", 34);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %-8d", 34);
    // compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %018d", 34);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %18d", 34);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %-18d", 34);
    // compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %02d", 343432);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %-2d", 34423342);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %9s", "Mundo");
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %-9s", "Mundo");
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %2s", "Mundo");
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %-2s", "Mundo");
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %12s", "Mundo");
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %-12s", "Mundo");
}
END_TEST

typedef struct {
    const char* fmt;
    int check_vs_sprintf;
    double input_value;
    const char * expected_string;
} double_test_pair;

START_TEST(test_float) {
    char str_csprintf[512];
    char str_sprintf[512];
    long unsigned int i;
    double_test_pair tests_exp_numbers[] = {
        {"%.5f", 1, 3.5f, NULL},
        {"%.5f", 1, -3.5f, NULL},
        // {"%.5f", 1, 9999999999999999999999999999.99999999999f*9999999999999999.0f, NULL},
        // {"%.5f", 1, -9999999999999999999999999999.99999999999f*9999999999999999.0f, NULL},
        // {"%.5f", 1, 0, NULL},
        {"%.5f", 1, 3.5458730589043f, NULL},
        {"%.5f", 1, -3.5458730589043f, NULL},
        // Round
        // {"%10.4f", 0, 3.5458730589043f, "3.5459"},
        // {"%10.4f", 0, -3.5458730589043f, "-3.5459"},
        // {"%07.5f", 1, 334243.5458730589043f, NULL},
        // Overflow go to exp notation
        // {"%010.5f", 0, -438374297892438974433.5458730589043f, "-4.38374e+20"},
        // {"%010.5f", 0, 393824092389048029343234243.5458730589043f,"3.93824e+26"},
    };

    for (i = 0; i < sizeof(tests_exp_numbers)/sizeof(tests_exp_numbers[0]); i ++) {
        sprintf(str_sprintf, tests_exp_numbers[i].fmt, tests_exp_numbers[i].input_value);
        s21_sprintf(str_csprintf, tests_exp_numbers[i].fmt, tests_exp_numbers[i].input_value);
        if (tests_exp_numbers[i].check_vs_sprintf) {
            ck_assert_msg(strcmp(str_sprintf, str_csprintf) == 0,
                   "Error String: i=%ld: sprintf: '%s' != result: '%s'",
                   i, str_sprintf, str_csprintf);
        } else {
            ck_assert_msg(strcmp(tests_exp_numbers[i].expected_string, str_csprintf) == 0,
                    "Error String: i=%ld: expected: '%s' != result: '%s' => sprintf:  '%s'",
                    i, tests_exp_numbers[i].expected_string, str_csprintf,
                    str_sprintf);
        }
    }
}
END_TEST

START_TEST(test_memcmp) {
    int result;
    char *str1 = "21school";
    char *str2 = "21school";
    char *str3 = "42school";

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
    double d[2] = {0.5, 0.6};
    double d2[2] = {0.5, 0.6};
    int d3[5] = {1, 1, 1, 1, 1};
    int d4[5] = {1, 1, 1, 1, 1};

    s21_memset(array, '0', n);
    ck_assert_str_eq(expected, array);
    ck_assert_str_eq(array, memset(array2, '0', n));
    ck_assert_str_eq(s21_memset(d, '0', n), memset(d2, '0', n));
    ck_assert_str_eq(s21_memset(d3, '0', n), memset(d4, '0', n));
}
END_TEST

START_TEST(test_strcmp) {
    int result;
    char *str1 = "school21";
    char *str2 = "school21";
    char *str3 = "school211";

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
    int n3 = 0;

    result = s21_strncmp(str1, str2, n1);
    ck_assert_int_eq(result, 0);
    ck_assert_int_eq(result, strncmp(str1, str2, n1));

    result = s21_strncmp(str1, str2, n3);
    ck_assert_int_eq(result, 0);
    ck_assert_int_eq(result, strncmp(str1, str2, n3));

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

    s21_strcpy(dest, src);
    ck_assert_str_eq(expected, dest);
    ck_assert_str_eq(dest, strcpy(res, src));
}
END_TEST

START_TEST(test_strncpy) {
    char src[13] = "Hello world!";
    char dest[25] = "aaaaaaaaaaaaaaaaaaaa";
    char res[25] = "aaaaaaaaaaaaaaaaaaaa";
    int n = 25;

    ck_assert_int_eq(s21_strncpy(dest, src, n)[15], strncpy(res, src, n)[15]);
}
END_TEST

START_TEST(test_strlen) {
    char str[25] = "Hello world!";

    ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strcspn) {
    char str[25] = "Hello world!";
    char rej[6] = "ab cd";
    char empty[] = "";

    ck_assert_int_eq(s21_strcspn(str, rej), strcspn(str, rej));
    ck_assert_int_eq(s21_strcspn(empty, rej), strcspn(empty, rej));
    ck_assert_int_eq(s21_strcspn(str, empty), strcspn(str, empty));
}
END_TEST

START_TEST(test_strspn) {
    char str[25] = "Hello world!";
    char acc[6] = "eollH";
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

    res = s21_insert(S21_NULL, to_insert, 7);
    ck_assert_pstr_eq(S21_NULL, res);
    if (res) free(res);

    res = s21_insert(string, S21_NULL, 7);
    ck_assert_pstr_eq(S21_NULL, res);
    if (res) free(res);

    res = s21_insert(string, to_insert, 100);
    ck_assert_pstr_eq(S21_NULL, res);
    if (res) free(res);
}
END_TEST

START_TEST(test_strpbrk) {
    char string[] = "Functions that will make our lives easier!";
    char chars[] = "";

    ck_assert_pstr_eq(s21_strpbrk(string, chars), strpbrk(string, chars));
    char chars2[] = "t";
    ck_assert_pstr_eq(s21_strpbrk(string, chars2), strpbrk(string, chars2));
    char chars3[2];
    chars3[0] = '\0';
    ck_assert_pstr_eq(s21_strpbrk(string, chars3), strpbrk(string, chars3));
}
END_TEST

START_TEST(test_strrchr) {
    char *string = "Snickersnee";
    char search_for = 'n';
    char string2[20] = "Snickersnee";
    string2[5] = '\0';

    ck_assert_pstr_eq(s21_strrchr(string, search_for), strrchr(string, search_for));
    ck_assert_pstr_eq(s21_strrchr(string2, '\0'), strrchr(string2, '\0'));
}
END_TEST

START_TEST(test_strchr) {
    char *string = "Snickersnee";
    char search_for = 'n';

    ck_assert_str_eq(s21_strchr(string, search_for), strchr(string, search_for));
}
END_TEST

START_TEST(test_to_upper) {
    char str[] = "this IS 5parta|";
    char *expected = "THIS IS 5PARTA|";
    char str2[] = "";

    char *res1 = s21_to_upper(str);
    char *res2 = s21_to_upper(str2);
    char *res3 = s21_to_upper(S21_NULL);
    ck_assert_pstr_eq(res1, expected);
    ck_assert_pstr_eq(res2, "");
    ck_assert_pstr_eq(res3, S21_NULL);
    if (res1) free(res1);
    if (res2) free(res2);
}
END_TEST

START_TEST(test_to_lower) {
    char str[] = "THIS is SPARTA!";
    char *expected = "this is sparta!";
    char str2[] = "";

    char *res1 = s21_to_lower(str);
    char *res2 = s21_to_lower(str2);
    char *res3 = s21_to_lower(S21_NULL);
    ck_assert_pstr_eq(res1, expected);
    ck_assert_pstr_eq(res2, "");
    ck_assert_pstr_eq(res3, S21_NULL);
    if (res1) free(res1);
    if (res2) free(res2);
}
END_TEST

START_TEST(test_strstr) {
    char *haystack = "This is Sparta!";
    char *haystack2 = "";
    char *needle = "is S";
    char *needle2 = "is S ";
    char *needle3 = "";

    ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
    ck_assert_pstr_eq(s21_strstr(haystack, needle2), strstr(haystack, needle2));
    ck_assert_pstr_eq(s21_strstr(haystack, needle3), strstr(haystack, needle3));
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
    char dst3[100] = "Hello";
    char dst4[100] = "Hello";
    ck_assert_str_eq(s21_strncat(dst3, src, 10), strncat(dst4, src, 10));
}
END_TEST

START_TEST(test_strtok) {
    char p[15] = "VK is Bad Guy";
    char exp[15] = "VK is Bad Guy";
    char *delim = "Visay";

    ck_assert_pstr_eq(s21_strtok(p, delim), strtok(exp, delim));
    ck_assert_pstr_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
    ck_assert_pstr_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
    ck_assert_pstr_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
}
END_TEST

START_TEST(test_strerror) {
    int errno = -1;
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

    res = s21_trim(S21_NULL, trim_chars);
    ck_assert_pstr_eq(res, S21_NULL);
    if (res) free(res);

    res = s21_trim(string, S21_NULL);
    ck_assert_pstr_eq(res, S21_NULL);
    if (res) free(res);

    char string2[] = "./er";
    res = s21_trim(string2, trim_chars);
    ck_assert_str_eq(res, "");
    if (res) free(res);
}

START_TEST(test_sprintf) {
    char orig[100] = {0};
    char res[100] = {0};
    extern int s21_sprintf(char *str, const char *format, ...);

    s21_sprintf(res, "%% %d %-d %+d % d", 123, 123, 123, 123);
    sprintf(orig, "%% %d %-d %+d % d", 123, 123, 123, 123);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%5d %-5d %+5d % 5d", 123, 123, 123, 123);
    sprintf(orig, "%5d %-5d %+5d % 5d", 123, 123, 123, 123);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%5.2d %-5.2d %+5.2d % 5.2d", 123, 123, 123, INT_MAX);
    sprintf(orig, "%5.2d %-5.2d %+5.2d % 5.2d", 123, 123, 123, INT_MAX);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%5.2d %-5.2d %+5.2d % 5.2d", -123, -123, -123, INT_MIN);
    sprintf(orig, "%5.2d %-5.2d %+5.2d % 5.2d", -123, -123, -123, INT_MIN);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%5.2ld %-5.2ld %+5.7li % 5.2ld", (long int)123, (long int)123, (long int)123,
                (long int)123);
    sprintf(orig, "%5.2ld %-5.2ld %+5.7li % 5.2ld", (long int)123, (long int)123, (long int)123,
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
    s21_sprintf(res, "%% %5.2u %-5.2u %%", 123u, 123U);
    sprintf(orig, "%% %5.2u %-5.2u %%", 123U, 123U);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%% %5.2lu %-5.5lu %%", (long unsigned int)123, (long unsigned int)123);
    sprintf(orig, "%% %5.2lu %-5.5lu %%", (long unsigned int)123, (long unsigned int)123);
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
    s21_sprintf(res, "%10f %-10.f %+10.2f % 10.10f", 1.123f, 2.523f, 1.135f, 1.123f);
    sprintf(orig, "%10f %-10.f %+10.2f % 10.10f", 1.123f, 2.523f, 1.135f, 1.123f);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%+10.2f", -1.125f);
    sprintf(orig, "%+10.2f", -1.125f);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%+10.5f", 0.0f);
    sprintf(orig, "%+10.5f", 0.0f);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%+10.0f", 0.0f);
    sprintf(orig, "%+10.0f", 0.0f);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%10f %-10.f %+10.2f % 10.10f", -1.123f, -2.123f, -1.125f, -1.123f);
    sprintf(orig, "%10f %-10.f %+10.2f % 10.10f", -1.123f, -2.123f, -1.125f, -1.123f);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%10f %-10.f %+10.2f % 15.13f", 1.123f, 2.523f, 1.135f, 1.123f);
    sprintf(orig, "%10f %-10.f %+10.2f % 15.13f", 1.123f, 2.523f, 1.135f, 1.123f);
    ck_assert_str_eq(res, orig);

    memset(orig, 0, sizeof(orig));
    memset(res, 0, sizeof(res));
    s21_sprintf(res, "%10s %-10.s %10.2s %10.10s %d", "-1.123f", "-1.123f", "-1.125f", "-1.123f", 5);
    sprintf(orig, "%10s %-10.s %10.2s %10.10s %d", "-1.123f", "-1.123f", "-1.125f", "-1.123f", 5);
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
    tcase_add_test(tc_sprintf, test_integer);
    tcase_add_test(tc_sprintf, test_long);
    tcase_add_test(tc_sprintf, test_float);
    tcase_add_test(tc_sprintf, test_padding);
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
