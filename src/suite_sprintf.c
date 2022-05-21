#include <limits.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"
#include "test_s21_string.h"

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
    const char *fmt;
    int check_vs_sprintf;
    double input_value;
    const char *expected_string;
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

    for (i = 0; i < sizeof(tests_exp_numbers) / sizeof(tests_exp_numbers[0]); i++) {
        sprintf(str_sprintf, tests_exp_numbers[i].fmt, tests_exp_numbers[i].input_value);
        s21_sprintf(str_csprintf, tests_exp_numbers[i].fmt, tests_exp_numbers[i].input_value);
        if (tests_exp_numbers[i].check_vs_sprintf) {
            ck_assert_msg(strcmp(str_sprintf, str_csprintf) == 0,
                          "Error String: i=%ld: sprintf: '%s' != result: '%s'", i, str_sprintf, str_csprintf);
        } else {
            ck_assert_msg(strcmp(tests_exp_numbers[i].expected_string, str_csprintf) == 0,
                          "Error String: i=%ld: expected: '%s' != result: '%s' => sprintf:  '%s'", i,
                          tests_exp_numbers[i].expected_string, str_csprintf, str_sprintf);
        }
    }
}
END_TEST

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

Suite *make_sprintf_suite(void) {
    Suite *s = suite_create("Sprintf function tests");
    TCase *tc_sprintf;

    tc_sprintf = tcase_create("sprintf");
    tcase_add_test(tc_sprintf, test_sprintf);
    tcase_add_test(tc_sprintf, test_integer);
    tcase_add_test(tc_sprintf, test_long);
    tcase_add_test(tc_sprintf, test_float);
    tcase_add_test(tc_sprintf, test_padding);
    suite_add_tcase(s, tc_sprintf);

    return s;
}