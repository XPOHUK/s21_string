CFLAGS = -Wall -Wextra -Werror
LIBSRC = $(wildcard ./s21_*.c)
LIBOBJ = $(LIBSRC:.c=.o)
LIB = libs21_string.a

all: s21_string.a test gcov_report

s21_string.a: $(LIBOBJ)
	ar rcs $(LIB) $(LIBOBJ)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

test: tests_obj test_s21_string.o
	gcc $(CFLAGS) $(LIBOBJ) test_s21_string.o -lcheck -lm -lpthread -lgcov -o $@
	./$@

tests_obj: $(LIBSRC)
	gcc $(CFLAGS) -c -fprofile-arcs -ftest-coverage $^

gcov_report: test
	gcovr -r . --html --html-details -o coverage_report.html

clean:
	rm -f $(LIBOBJ) coverage* test *.gcda *.gcno test_s21_string.o 

fclean: clean
	rm -f $(LIB)

rebuild:
	make -B all

