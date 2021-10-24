all: test

test: main.cpp
	g++ -Wall -o  tax main.cpp

