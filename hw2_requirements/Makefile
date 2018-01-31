CPPFLAGS=-std=c++11 -g -O3

searchsort: main.o
	    g++ main.o -o searchsort

main.o: main.cpp SearchSort.h
	g++ $(CPPFLAGS) -c main.cpp
