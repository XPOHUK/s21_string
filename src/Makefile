CFLAGS = -Wall -Wextra -Werror
LIBSRC = $(wildcard s21_*.c)
LIBOBJ = $(LIBSRC:.c=.o)
LIB = libs21_string.a

all: s21_string.a cpplint test gcov_report

s21_string.a: $(LIBOBJ)
	ar rcs $(LIB) $(LIBOBJ)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

test: tests_obj test_s21_string.o
	gcc $(CFLAGS) $(LIBOBJ) test_s21_string.o -lcheck -lm -lpthread -lgcov -o $@
	./$@

tests_obj: $(LIBSRC)
	gcc $(CFLAGS) -O2 -std=c11 -pedantic -Wno-stringop-truncation -ftrapv -Wfloat-equal -Wundef -Wformat=2 -c -g -fprofile-arcs -ftest-coverage $^

cpplint: $(LIBSRC)
	cp ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py --extensions=c $^

gcov_report: test
	gcovr -r . --html --html-details -o coverage_report.html

clean:
	rm -f $(LIBOBJ) coverage* test *.gcda *.gcno test_s21_string.o CPPLINT.cfg

fclean: clean
	rm -f $(LIB)

rebuild:
	make -B

