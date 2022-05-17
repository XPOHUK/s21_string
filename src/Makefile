UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    CMD = xdg-open ./coverage_report.html
endif
ifeq ($(UNAME_S),Darwin)
    CMD = open ./coverage_report.html
endif
CFLAGS = -Wall -Wextra -Werror
LIBSRC = $(wildcard s21_*.c)
LIBOBJ = $(LIBSRC:.c=.o)
LIB = s21_string.a

all: cpplint test gcov_report s21_string.a

s21_string.a: $(LIBOBJ)
	ar rcs $(LIB) $(LIBOBJ)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

test: tests_lib test_s21_string.o
	gcc $(CFLAGS) test_s21_string.o s21_string.a -lcheck -lm -lpthread -lgcov -o $@
	./$@
	rm -f *.o *.a

tests_lib: tests_obj
	ar rcs $(LIB) $(LIBOBJ)

tests_obj: $(LIBSRC)
	gcc $(CFLAGS) -O0 -std=c11 -pedantic -Wno-stringop-truncation -ftrapv -Wfloat-equal -Wundef -Wformat=2 -c -g -fprofile-arcs -ftest-coverage $^

cpplint: $(LIBSRC)
	cp ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py --extensions=c $^ s21_string.h s21_strerror.h test_s21_string.c
	rm ./CPPLINT.cfg

gcov_report: test
	gcovr -r . --html --html-details -o coverage_report.html
	$(CMD)
	rm -f *.gcda *.gcno

clean:
	rm -f $(LIBOBJ) coverage* test *.gcda *.gcno test_s21_string.o test-s21_string.a

fclean: clean
	rm -f $(LIB)

rebuild:
	make -B

