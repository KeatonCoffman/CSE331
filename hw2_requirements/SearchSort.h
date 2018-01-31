/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SearchSort.h
 * Author: Keaton Coffman
 * Homework 2
 * Due September 15
 */

#ifndef SEARCHSORT_H_
#define SEARCHSORT_H_

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
void insert_sort_dec(vector<Comparable> &A){
  	int n = A.size();
	int tmp;
	for(int i=1; i<n;i++){
		int key = A[i];
		int j = i;		
		while (j>0 && A[j-1]<key){
		        tmp = A[j];
		        A[j]=A[j-1];
                        A[j-1]=tmp;
			j--;
			
 		}
 	        
	}
	
}

template <typename Comparable>
void simpleprint(vector<Comparable> nums){
	for (int item:nums){
		cout<<item<<endl;
	}
}




#endif /* SEARCHSORT_H_ */
