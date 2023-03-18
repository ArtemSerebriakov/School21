CC=gcc
CFLAGS=-c -Wall -Werror -Wextra
all: s21_cat
s21_cat: s21_cat.o s21_main.o
	$(CC) -Wall -Wextra -Werror s21_cat.o s21_main.o -o s21_cat
s21_main.o: s21_main.c
	$(CC) $(CFLAGS) s21_main.c
s21_cat.o: s21_cat.c
	$(CC) $(CFLAGS) s21_cat.c
test_style:
	cp ../../materials/linters/.clang-format ..
	cd .. && exec clang-format -i -style=Google cat/*.c
	cd .. && exec clang-format -i -style=Google cat/*.h
clean: 
	rm -rf *.o s21_cat
rebuild:
	$(MAKE) clean
	$(MAKE) all