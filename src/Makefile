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
SUITESRC = $(wildcard suite_*.c)
SUITEOBJ = $(SUITESRC:.c=.o)
LIB = s21_string.a

all: cpplint test gcov_report s21_string.a

s21_string.a: $(LIBOBJ)
	ar rcs $(LIB) $(LIBOBJ)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

test: test_$(LIB) test_s21_string.o $(SUITEOBJ)
	gcc $(CFLAGS) tests/$(LIB) test_s21_string.o $(SUITEOBJ) -fsanitize=address -g -lcheck -lm -lpthread -lgcov -o $@
	./$@
	rm -f *.o *.a

test_$(LIB): $(addprefix tests/,$(LIBOBJ))
	ar rcs tests/$(LIB) $^

tests/%.o: %.c
	gcc $(CFLAGS) -O0 -std=c11 -fsanitize=address -pedantic -Wno-stringop-truncation -ftrapv -Wundef -Wformat=2 -c -g -fprofile-arcs -ftest-coverage $< -o $@

tests_obj: $(LIBSRC)
	gcc $(CFLAGS) -O0 -std=c11 -fsanitize=address -pedantic -Wno-stringop-truncation -ftrapv -Wundef -Wformat=2 -c -g -fprofile-arcs -ftest-coverage $^

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

