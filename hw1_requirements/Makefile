CPPFLAGS=-std=c++11 -g -O3

kthsearch: main.o
	    g++ main.o -o kthsearch

main.o: main.cpp KthLargest.h
	g++ $(CPPFLAGS) -c main.cpp
