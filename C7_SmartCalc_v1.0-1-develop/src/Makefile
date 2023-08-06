CC = gcc
FLAGS =  -Wall -Werror -Wextra  -std=c11
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
MAC_FLAGS=-lcheck -lm
VALGRIND_FLAGS = --log-file="valgrind.txt" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med
FILES=$(wildcard ./calc/*.c)
OBJ=$(patsubst %.c,%.o,$(FILES))

all: install

install:
	make clean
	mkdir build
	cd calc && qmake && make && make clean && rm Makefile && cd ../ && mv calc/calculator.app build

uninstall:
	rm -rf build

test:
	${CC} $(FLAGS) calc/unit_tests/s21_main_test.c calc/unit_tests/s21_smart_calc_test.c calc/polish.c calc/parser.c calc/stack.c calc/validator.c $< -o unit_test $(MAC_FLAGS) -g
	./unit_test

gcov_report: clean_gcov
	$(CC) $(FLAGS) $(GCOV_FLAGS) calc/unit_tests/s21_main_test.c calc/unit_tests/s21_smart_calc_test.c calc/polish.c calc/parser.c calc/stack.c -o test $(MAC_FLAGS)
	./test
	lcov -t "stest" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open ./report/index.html

dvi:
	open doc.html

style_check:
	cp ../materials/linters/.clang-format ../src
	clang-format -i -style=Google calc/*.cpp calc/*.c calc/*.h calc/unit_tests/*.c calc/unit_tests/*.h
	clang-format -n -style=Google calc/*.cpp calc/*.c calc/*.h calc/unit_tests/*.c calc/unit_tests/*.h
	rm .clang-format

memory_check:
	$(CC) $(FLAGS) $(GCOV_FLAGS) calc/unit_tests/s21_main_test.c calc/unit_tests/s21_smart_calc_test.c calc/polish.c calc/parser.c calc/stack.c calc/validator.c $< -o memory_test $(MAC_FLAGS) -g
	CK_FORK=no leaks --atExit -- ./memory_test

dist:
	rm -rf Archive_smartcalc_v1.0/
	mkdir Archive_smartcalc_v1.0/
	mkdir Archive_smartcalc_v1.0/src
	mv ./build/calculator.app Archive_smartcalc_v1.0/src/
	tar cvzf Archive_smartcalc_v1.0.tgz Archive_smartcalc_v1.0/
	rm -rf Archive_smartcalc_v1.0/

clean_gcov:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf test
	rm -rf report
	rm -rf postreport.info

calc.a: $(FILES)
	$(CC) -c $(FLAGS) $(FILES)
	mv *.o ./calc
	ar rc $@ $(OBJ)
	ranlib $@
	rm -rf *.o

clean:
	rm -rf *.{a,o,dSYM,out}
	rm -rf $(EXECUTABLE)
	rm -rf gcov_report
	rm -rf report
	rm -rf CPPLINT.cfg
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf Archive_smartcalc_v1.0 
	rm -rf *tgz
	rm -rf build
	rm -rf calc/qmake_qmake_qm_files.qrc
	rm -rf calc/.qmake.stash
	rm -rf calc/*.o
	rm -rf calc/unit_test.dSYM
	rm -rf unit_test
	rm -rf memory_test
