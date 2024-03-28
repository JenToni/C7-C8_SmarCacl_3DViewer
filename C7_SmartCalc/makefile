CC=gcc -g
FLAGS= -g -Wall -Wextra -Werror -std=c11
TEST_FLAGS=-lcheck -lpthread -pthread -lm
TEST = tests/
SRC = $(wildcard ./S21_calc/Back/*.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

TEST_SRC = $(wildcard $(TEST)*.c)
TEST_OBJ = $(patsubst $(TEST)%.c, $(TEST)%.o, $(TEST_SRC))

FLAGS = -std=c11 -Wall -Werror -Wextra
TEST_FLAGS = -lcheck -lpthread -pthread -lm 

ifeq ($(shell uname -s),Linux)
	TEST_FLAGS += -lsubunit -lgcov -lrt
endif

all: uninstall clean test gcov_report install dvi dist

s21_calc.a : $(OBJ)
	ar rc s21_calc.a $(OBJ)
	ranlib s21_calc.a

test.a: $(TEST_OBJ)
	ar r test.a $^

test: s21_calc.a test.a 
	$(CC) $(TEST_OBJ) test.a  s21_calc.a $(TEST_FLAGS) -o test.out 
	./test.out

gcov_report: clean
	$(CC) $(FLAGS) -fprofile-arcs -ftest-coverage $(TEST_SRC) $(SRC) -o test $(TEST_FLAGS)
	./test
	lcov -t "s21_calc.a" -o s21_calc.info -c -d .
	genhtml -o gcov_report s21_calc.info
	open gcov_report/index.html

	
leaks: s21_calc.a test.a 
	$(CC) $(TEST_OBJ) test.a  s21_calc.a $(TEST_FLAGS) -o test.out 
ifeq ($(shell uname -s), Linux)
	valgrind --leak-check=yes  ./test.out
else
	leaks --atExit -- ./test.out
endif

style_fix:
	clang-format -style=Google -i ./S21_calc/*.cpp $(SRC) ./S21_calc/Back/*.h

style:
	clang-format -style=Google -n $(SRC) ./S21_calc/Back/*.h ./S21_Calc/*.cpp

install:
	mkdir build
	cd S21_calc && qmake && make && make clean  && rm Makefile && mv Calck.app ../build

start:
	open build/Calck.app
	
uninstall:
	rm -rf build 

dist: 
	tar -cf Calck.tar S21_Calc

dvi:
#d readme/ && texi2dvi --pdf document.tex 
	open ./readme/document.pdf

#brew install qt

clean:
	rm -rf ./S21_calc/Back/*.o *.a ./tests/*.o *.out build ./S21_Calc/.qmake.stash *.gcda *.gcno test *.info gcov_report *.tar

