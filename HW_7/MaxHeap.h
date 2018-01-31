
/* 
 * File:   MaxHeap.h
 * Author: Keaton Coffman
 * Homework 6
 * CSE 331
 * Created on November 8, 2016, 5:03 PM
 */

#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <cmath> 
using namespace std;
template <typename T>
class myMaxHeap 
{
private:
    long currentsize;
    vector<T> data;

	// Lecture 11 Slide 48
	// Function: Percolates an item down the Max Heap
	// Pre: Heap is intitialized
	// Post: Percolates the heap down to proper position in heap

    void percolateDown(int hole)  {
		int child;
		T temp_ = std::move(data.at(hole));

		for (; hole * 2 <= currentsize; hole = child) {
			child = hole * 2;
			if (child != currentsize && data[child + 1] < data[child]) {
				++child;
			}
			if (data[child] < temp_) {
				data[hole] = std::move(data[child]);
			}
			else {
				break;
			}
		}
		data[hole] = temp_;
    }

	// Function: Percolate an item up a tree
	// Pre: Heap is intitialized
	// Post: Percolates an item up the heap to fill the hole parameter

    void percolateUp(int hole) {
		for(;data[hole] > data[hole/2] && hole > 1;hole/=2){
			int temp_ = data[hole];
			data[hole] = data[hole/2];
			data[hole/2] = temp_;
		}
    }

	// Function: Create the Heap
	// Pre: Heap is intitialized
	// Post: Creates a heap from the middle of the vector down 
    void heapCreate() {
		for (int i = currentsize / 2; i > 0; i--) {
			percolateDown(i);
		}
    } // end heapCreate

public:
   
	// Pre: Overflow Subclass 
	// Post: Throws error and prints string "n" 
	class HeapOverflow: public std::runtime_error { 
		public: 
			explicit HeapOverflow(string n): std::runtime_error(n){}; 
	}; 
	 
	// Pre: Underflow Subclass 
	// Post: Throws error and prints string "n" 
	class HeapUnderflow: public std::runtime_error { 
		public: 
			explicit HeapUnderflow(string n): std::runtime_error(n){}; 
	}; 
 

   //rest of the methods defined in requirements document...

   // Function: Checks if the heap is empty
   // Pre: Heap is intitialized
   // Post: Check if the heap is empty return true if it is else return false
	bool isEmpty() const {
		if(currentsize == 0)
			return true;
		else
			return false;
	}

	// Function: Gets the index of the item
	// Pre: Heap is intitialized
	// Post: If empty throws an error else return the index of the data
	const T getItem(int index) {
		if(isEmpty()){
			throw HeapUnderflow("Could not get item because heap is empty \n");
		}
		else{
		return data[index];
		}
	}

	// Function: Displays the max heap
	// Pre: Heap is intitialized
	// Post: If empty return underflow else display everything in max heap
	void display() {
		if(isEmpty()){
			throw HeapUnderflow("Could not display items because heap is empty \n");
		}
		else{
			for (auto item: data) {
			cout << item << endl;
			}
		}	
	}

	// Function: Get the height of the heap
	// Pre: Heap is intitialized
	// Post: If the heap is empty 
	int getHeight() const {
		if(isEmpty()){
			return -1;
		}
		else{	
			return (log2(currentsize));
		}
	}

	// Function: Get the number of nodes in the heap
	// Pre: Heap is intitialized
	// Post: If empty returns 0 else return currentsize
	int getNumberOfNodes() const {
		if(isEmpty()){
			return 0;
		}
		else{		
		return currentsize;
		}
	}

	// Function: Clear the heap
	// Pre: Heap is intitialized
	// Post: Clears the data vector and sets currentsize to 0
	void clear() {
		currentsize = 0;
		data.clear();
	}

	// Function: Retrieve the root of the max heap
	// Pre: Heap is intitialized
	// Post: Returns the top of data vector
	T peekTop() const {
		if(isEmpty()){
			throw HeapUnderflow("Could not get top item because heap is empty \n");
		}
		else{
		return data[1];
		}
	}

	// Function: Add an item to the heap
	// Pre: Heap is intitialized
	// Post: Increment currentsize, pushes back newData, and percolates the newdata up the heap
	void add(const T& newData) {
		++currentsize;
		data.push_back(newData);
		percolateUp(currentsize-1);
	}

	// Function: Removes an item from the heap
	// Pre: Heap is intitialized
	// Post: If empty throws underflow, else remove first item and percolate the heap down
	void remove() {
		if(isEmpty()){
			throw HeapUnderflow("The heap is empty \n");
		}
		else{
		data[1]=data[currentsize--];
		percolateDown(1);
		}
	}

	// Function: Increases a key value in the heap
	// Pre: Heap is intitialized
	// Post: Increment a value in the heap according to the parameter and then percolate that value up the heap
	void increaseKey(int p, T positiveValue) {
		data[p] = data[p] + positiveValue;
		percolateUp(p);
	}

	// Function: Decreases a key value in the heap
	// Pre: Heap is intitialized
	// Post: Decrement a value in the heap according to the parameter and then percolate that value down the heap
	void decreaseKey(int p, T positiveValue) {
		data[p] = data[p] - positiveValue;
		percolateDown(p);
	}

	// Function: Make a heap according to an input parameter
	// Pre: Heap is intitialized
	// Post: Set currentsize, pushback 0 for indexing purposes, for loop to add and percolate each item in the heap
	myMaxHeap(vector<T>&input) {
		currentsize = input.size();
		data.push_back(0);
		for(int i=0;i< currentsize;++i){
			data.push_back(input[i]);
			percolateUp(i+1);
		}
		
	}
};
#endif /* MAXHEAP_H */

