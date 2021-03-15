APP_NAME=uTests
FLAGS=-Wall -o $(APP_NAME)

APP_SRC=tests.cpp
SRC:=$(shell find src -name '*.cpp')

all: main

main:
	clang++ $(APP_SRC) $(SRC) $(FLAGS) && ./$(APP_NAME)

memcheck:
	clang++ $(APP_SRC) $(SRC) $(FLAGS) && valgrind --leak-check=full ./$(APP_NAME)