#include <check.h>
#include <stdlib.h>

#include "s21_string.h"

START_TEST(test_memchr) {
    char *ch;
    char *s = "21school";
    extern void *s21_memchr(const void *str, int c, size_t n);

    ch = s21_memchr(s, 's', sizeof(s));
    ck_assert_str_eq(ch, "school");
} END_TEST

Suite *memchr_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Memchr");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_memchr);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = memchr_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_NORMAL);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
