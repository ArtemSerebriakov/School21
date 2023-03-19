#   _____      _                 _   ___  __
#  / ____|    | |               | | |__ \/_ |
# | (___   ___| |__   ___   ___ | |    ) || |
#  \___ \ / __| '_ \ / _ \ / _ \| |   / / | |
#  ____) | (__| | | | (_) | (_) | |  / /_ | |
# |_____/ \___|_| |_|\___/ \___/|_| |____||_|

# target section
ifeq ($(OS),Windows_NT)
	LIB_DECIMAL=libs21_decimal.lib
	LIB_DECIMAL_TARGET=s21_decimal.lib
else
	LIB_DECIMAL=libs21_decimal.a
	LIB_DECIMAL_TARGET=s21_decimal.a
endif

# compile section
CC=gcc
CC_FLAGS=-std=c11 -O2
LCOV_FLAGS=--coverage

# icnlude lib section
ifeq ($(OS),Windows_NT)
	INC_LIB_DECIMAL=-L. -ls21_decimal
	INC_LIB_CHECK=-lcheck
else ifeq ($(shell uname), Linux)
	INC_LIB_DECIMAL=-lm -L. -ls21_decimal
	INC_LIB_CHECK=-lcheck -pthread -lrt -lm -lsubunit
else
	INC_LIB_DECIMAL=-L. -ls21_decimal
	INC_LIB_CHECK=-lcheck
endif

# all headers decimal section
HEADERS_DECIMAL=$(wildcard s21_bcd/s21_*/*.h s21_decimal/s21_*/*.h)

# all src decimal section
SRC_DECIMAL=$(wildcard s21_bcd/s21_*/*.c s21_decimal/s21_*/*.c)
SRC_TEST_DECIMAL=$(wildcard s21_test_decimal/*.c)

# all obj decimal section
OBJ_DECIMAL=$(patsubst %.c,%.o,$(SRC_DECIMAL))

# make
all: $(LIB_DECIMAL_TARGET)

clean:
	@rm -fr a.out $(OBJ_DECIMAL) *.a
	@rm -fr ./report *.gcno *.gcda *.info *.gcov

test: $(LIB_DECIMAL_TARGET)
	@$(CC) $(CC_FLAGS) $(SRC_TEST_DECIMAL) $(INC_LIB_CHECK) $(INC_LIB_DECIMAL)
	@./a.out

$(LIB_DECIMAL_TARGET): $(OBJ_DECIMAL) $(HEADERS_DECIMAL)
	ar rc $(LIB_DECIMAL) $?
	ranlib $(LIB_DECIMAL)
	@cp $(LIB_DECIMAL) $@

gcov_report:
	@$(CC) $(CC_FLAGS) $(SRC_DECIMAL) $(SRC_TEST_DECIMAL) $(INC_LIB_CHECK) $(LCOV_FLAGS)
	@./a.out
	lcov -t a.out -o report.info --no-external -c -d .
	genhtml -o report report.info
	@rm -f *.gcno *.gcda *.info a.out *.gcov
	open ./report/index.html


%.o: %.c $(HEADERS_DECIMAL)
	$(CC) $(CC_FLAGS) -c $< -o $@


main: $(LIB_DECIMAL_TARGET) main.c
	$(CC) $(CC_FLAGS) main.c $(INC_LIB_DECIMAL)
	./a.out


.PHONY: all clean test gcov_report clang_format

