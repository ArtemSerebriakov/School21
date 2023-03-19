CC= gcc 
FLAGS = -Wall -Werror -Wextra -std=c11
SRC = s21_*.c
TEST_LIBS = -lcheck -lm -lpthread
TEST_FLAGS=-g
OBJECTS = $(SRC:%.c=%.o)
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
OS = $(shell uname -s)
OPEN = open
ifeq ($(OS), Darwin)
	TEST_LIBS=-lcheck
else
	TEST_LIBS=-lcheck -lsubunit -pthread -lrt -lm
	OPEN=xdg-open
endif

all: clean s21_math.a test gcov_report

s21_math.a: $(OBJECTS)
	$(CC) -c $(FLAGS) $(SRC) $(shell pkg-config --libs --cflags check)
	ar rcs s21_math.a $(OBJECTS)

test: s21_math.a
	$(CC) -c $(FLAGS) test.c -o test.o $(shell pkg-config --libs --cflags check)
	$(CC) test.o s21_math.a $(TEST_LIBS) -o test $(shell pkg-config --libs --cflags check)
	./test

gcov_report: test
	$(CC) $(FLAGS) --coverage test.c $(SRC) $(TEST_LIBS) -o gcov_test $(shell pkg-config --libs --cflags check)
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o  gcov_test.info   -c -d .
	genhtml -o report/ gcov_test.info
	$(OPEN) ./report/src/index.html

clean:
	rm -rf *.o
	rm -rf gcov_test
	rm -rf test
	rm -rf *.gcda *.gcno *.info
	rm -rf ./test_output/ 
	rm -rf s21_math.a
	rm -rf ./report/ 

check:
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config *.c *.h 
	clang-format -i -style=google *.c *.h
	clang-format -n -style=google *.c *.h
