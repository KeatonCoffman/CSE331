/*
 * SearchSort2.h
 *
 *  Created on: September 27, 2016
 *      Author: Keaton Coffman
 * 		Homework 3
 * 		
 */

#ifndef SEARCHSORT2_H_
#define SEARCHSORT2_H_
#include <iostream>
#include <vector>


using namespace std;

template <typename Comparable>
void insertion_sort(vector<Comparable> &A){
	int n = A.size();
	int tmp;
	for(int i=1; i<n;i++){
		int key = A[i];
		int j = i;		
		while (j>0 && A[j-1]>key){
		        tmp = A[j];
		        A[j]=A[j-1];
                        A[j-1]=tmp;
			j--;
			
 		}
 	        
	}
}

template <typename Comparable>
int binarySearch(vector <Comparable> &items, const int key){
	int lower_bound = 0;
	int upper_bound = items.size() - 1;
	while (lower_bound <= upper_bound) {
		int midpoint = (upper_bound + lower_bound) / 2;
		if (items[midpoint] < key) {
			upper_bound = midpoint- 1;
		}
		if (items[midpoint] > key) {
			lower_bound = midpoint + 1;
		}
		else {
			return midpoint-1;
		}
	}
}


template <typename Comparable>
int rec_helper(vector<Comparable> &items, const int key, int lower_bound, int upper_bound) {
	if (lower_bound > upper_bound) {
		return lower_bound;
	}
	int midpoint = lower_bound +((upper_bound-lower_bound) / 2);
	if (key == items[midpoint]) {
		return midpoint;
	}
	if (items[midpoint] > key) {
		return rec_helper(items, key, lower_bound, midpoint-1);
	}	
	else{
		return rec_helper(items, key, midpoint+1, upper_bound);
	}
}

template <typename Comparable>
int recBinSearch(vector<Comparable> &items, const int key){
	insertion_sort(items);
	return rec_helper(items,key, 0, (items.size()-1));
}



#endif /* SEARCHSORT2_H_ */
