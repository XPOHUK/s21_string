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

test:

gcov_report:

clean:
	rm -f $(LIBOBJ) $(TESTOBJ)

fclean: clean
	rm -f $(LIB)

rebuild:
	make -B all

