UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    CMD = xdg-open ./coverage_report.html
endif
ifeq ($(UNAME_S),Darwin)
    CMD = open ./coverage_report.html
endif
CFLAGS = -Wall -Wextra -Werror -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk $(shell pkg-config --cflags check)
LIBSRC = $(wildcard s21_*.c)
TESTSRC = $(wildcard suite*) test_s21_string.c
LIBOBJ = $(LIBSRC:.c=.o)
LIB = s21_string.a

all: cpplint test gcov_report s21_string.a

s21_string.a: $(LIBOBJ)
	ar rcs $(LIB) $(LIBOBJ)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

test: tests_lib $(TESTSRC:.c=.o)
	gcc $(CFLAGS) $(TESTSRC:.c=.o) s21_string.a -fsanitize=address -g -lcheck -lm -lpthread --coverage -o $@ $(shell pkg-config --libs check)
	./$@
	rm -f *.o *.a

tests_lib: tests_obj
	ar rcs $(LIB) $(LIBOBJ)

tests_obj: $(LIBSRC)
	gcc $(CFLAGS) -O0 -std=c11 -fsanitize=address -pedantic -ftrapv -Wundef -Wformat=2 -c -g -fprofile-arcs -ftest-coverage $^

cpplint: 
	cp ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
	rm ./CPPLINT.cfg

gcov_report: test
	gcovr -r . --html --html-details -o coverage_report.html
	$(CMD)
	rm -f *.gcda *.gcno

clean:
	rm -f coverage* test *.gcda *.gcno *.o

fclean: clean
	rm -f $(LIB)

rebuild:
	make -B

