INCLUDE_DIRS= include
INC_PARAMS=$(foreach d, $(INCLUDE_DIRS), -I$d)
APP_NAME=uTests.app
FLAGS=-Wall -o $(APP_NAME) $(INC_PARAMS)

APP_SRC=tests.cpp
SRC:=$(shell find src -name '*.cpp')

all: main

main:
	clang++ $(APP_SRC) $(SRC) $(FLAGS) && ./$(APP_NAME)

memcheck:
	clang++ $(APP_SRC) $(SRC) $(FLAGS) -fsanitize=address -fno-omit-frame-pointer && ./$(APP_NAME)

zip:
	zip unitTest.zip . -r -x uTests.app