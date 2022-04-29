CFLAGS = -Wall -Wextra -Werror
LIBSRC = $(wildcard ./s21_*.c)
TESTSRC = $(wildcard ./test*.c)
LIBOBJ = $(LIBSRC:.c=.o)
TESTOBJ = $(TESTSRC:.c=.o)
LIB = libs21_string.a

all: s21_string.a test gcov_report

s21_string.a: $(LIBOBJ)
	ar rcs $(LIB) $(LIBOBJ)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

test: test_memchr

test_memchr: memchr_obj test_s21_memchr.o
	gcc $(CFLAGS) s21_memchr.o test_s21_memchr.o -lcheck -lm -lpthread -lgcov -o $@
	./$@

memchr_obj: s21_memchr.c
	gcc $(CFLAGS) -c -fprofile-arcs -ftest-coverage $<

gcov_report: test
	gcovr -r . --html --html-details -o coverage_report.html

clean:
	rm -f $(LIBOBJ) $(TESTOBJ)

fclean: clean
	rm -f $(LIB)

rebuild:
	make -B all

