NAME=my_matrix
GCC :=gcc -std=c11
CFLAGS :=-Wall -Werror -Wextra 
GCOV :=-fprofile-arcs -ftest-coverage
HEADERS := my_matrix.h
SOURCES := my_matrix.c
OBJECTS := my_matrix.o
TEST_NAME := test
TEST_SOURCES := test.c

OS=$(shell uname -s)
ifeq ($(OS),Darwin)
	CHECKFLAGS=-lcheck
	OPENFILE=open
else
	CHECKFLAGS=-lcheck -pthread -lrt -lm -lsubunit -ldl
	OPENFILE=xdg-open
endif

.PHONY: test

all: test gcov_report

$(NAME).a:
	$(GCC) $(CFLAGS) -c $(SOURCES) -o $(OBJECTS)
	@ar rcs lib$(NAME).a $(OBJECTS)
	@ranlib lib$(NAME).a

test: $(NAME).a
	@$(GCC) $(TEST_SOURCES) -L. -l$(NAME) $(GCOV) $(CHECKFLAGS) -o $(TEST_NAME)
	@./$(TEST_NAME)

gcov_report: 
	@$(GCC) $(GCOV) $(TEST_SOURCES) $(SOURCES) $(CHECKFLAGS) -o $(TEST_NAME)
	@./$(TEST_NAME)
	@lcov -t "GcovReport" -o GcovReport.info -c -d .
	@genhtml -o report GcovReport.info
	$(OPENFILE) ./report/index.html
	@rm -f *.gcno *.gcda *.info

clean:
	@rm -f *.o *.a a.out
	@rm -f $(TEST_NAME)
	@rm -f *.gcno *.gcda *.info
	@rm -rf ./report
	@rm -f valgrind-out.txt

rebuild: clean all

#----Checking
linter:
	echo "--------Linter Cpplint.py--------"
	python3 ./linters/cpplint.py --extensions=c $(SOURCES) $(TEST_SOURCES) $(HEADERS)
leaks:
	echo "--------Leaks Checking--------"
	CK_FORK=no leaks -atExit -- ./$(TEST_NAME)
cppcheck:
	echo "--------Static Code Checking--------"
	cppcheck --enable=all --suppress=missingIncludeSystem ./
valgrind:
	CK_FORK=no valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --show-reachable=yes ./$(TEST_NAME) >valgrind-out.txt 2>&1
