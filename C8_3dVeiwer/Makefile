SHELL = /bin/sh
CC=gcc
CFLAGS= -std=c11 -Wall -Wextra -Werror
OS=$(shell uname)
APP = viewer.app

ifeq ($(OS), Linux)
	TEST_FLAGS = $(shell pkg-config --libs check) -lsubunit -lcheck -lm -lpthread
	APP = viewer
else
	TEST_FLAGS = -lcheck -lpthread
endif

DIST = 3d_viewer-1.0
SRC = $(wildcard functions/*.c)
SRC_TEST = $(wildcard tests/*.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
OBJ_TESTS = $(patsubst %.c, %.o, $(SRC_TEST))
AR = ar
RANLIB = ranlib


all: clean dvi dist test gcov_report install

dist:
	@rm -rf $(DIST)
	@mkdir $(DIST)
	@cp -r functions tests viewer Makefile $(DIST)/
	tar cvzf $(DIST).tgz $(DIST)
	@-rm -rf $(DIST)/

install:
	@rm -rf ${PWD}/build
	@mkdir ${PWD}/build
	@qmake6 viewer/viewer.pro -o ${PWD}/build
	$(MAKE) -C ${PWD}/build
	@cp -r ${PWD}/build/$(APP) ${HOME}/Desktop
	
uninstall:
	@rm -rf ${PWD}/build
	@rm -rf ${HOME}/Desktop/$(APP)

dvi:
ifeq ($(OS), Darwin) 
	@-doxygen Doxyfile
	@open html/index.html
else
	@-Doxygen.exe Doxyfile
	@-open html/index.html
endif

clean:
	@rm -rf s21_3d_viewer.a
	@rm -rf test
	@rm -rf $(OBJ) $(OBJ_TESTS)
	@rm -rf *.info *.gcno *.gch *.gcda
	@rm -rf report *.o *.out
	@rm -rf test.dSYM
	@rm -rf latex
	@rm -rf html
	@rm -rf $(DIST).tgz

s21_3d_viewer.a: $(OBJ) $(OBJ_LIBS)
	@$(AR) -rcs s21_3d_viewer.a $(OBJ) $(OBJ_LIBS)
	$(RANLIB) s21_3d_viewer.a


test: clean s21_3d_viewer.a $(OBJ_TESTS)
	@$(CC) $(CFLAGS) $(OBJ_TESTS) $(TEST_FLAGS) s21_3d_viewer.a  -o test
	@./test


gcov_report: clean $(OBJ_TESTS)
	$(CC) $(CFLAGS) -ggdb --coverage $(OBJ_TESTS) $(SRC) -o test $(TEST_FLAGS)
	./test
	@lcov -t "s21_3d_viewer.a" -o s21_3d_viewer.info -c -d .
	@genhtml -o report s21_3d_viewer.info
	open report/index.html

leaks: clean s21_3d_viewer.a $(OBJ_TESTS)
	@$(CC) -ggdb --coverage $(SRC) $(SRC_TEST) $(TEST_FLAGS) s21_3d_viewer.a  -o test
ifeq ($(shell uname -s), Linux)
	valgrind --leak-check=yes  ./test
else
	leaks --atExit -- ./test
endif

stylefix: 
	clang-format -style=Google -i $(SRC) $(SRC_TEST) ./tests/*.h ./functions/3d_viewer.h ./viewer/*.cpp ./viewer/*.h

check:
	clang-format -style=Google -n $(SRC) $(SRC_TEST) ./tests/*.h ./functions/3d_viewer.h ./viewer/*.cpp ./viewer/*.h
