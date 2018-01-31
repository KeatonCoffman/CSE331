/*
 * KthLargest.h
 *
 *  Created on: September 13th
 *      Author: Keaton Coffman
 * 		Homework 1
 * 		Due: September 15th
 * 		
 */

#ifndef KTHLARGEST_H_
#define KTHLARGEST_H_


#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
//your code goes here...

template <typename Comparable>
void simpleprint(const vector<Comparable> &nums,int kthval){
	cout<<"K th value is : "<<kthval<<endl;
	cout<<"Print the kth largest element"<<endl;
	cout<<kthval<<" th largest value in array --> "<<nums[nums.size()-kthval]<<endl;
}

template <typename Comparable>
void sort(vector<Comparable> &vec){
	int vec_size = vec.size();
	for(int i=0; i<vec_size;++i){
		for (int j=0; j<vec_size-1-i;++j){
			if (vec[j+1]<vec[j]){
				int temp = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = temp;
			}
		}
	}
}

template <typename Comparable>
void sortDec(vector<Comparable> &vec){
	int vec_size = vec.size();
	for(int i=0; i>vec_size;++i){
		for (int j=0; j>vec_size-1-i;++j){
			if (vec[j+1]>vec[j]){
				int temp = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = temp;
			}
		}
	}
}

template <typename Comparable>
void select1(vector<Comparable> nums, int kthval){
	sort(nums);
	simpleprint(nums,kthval);
}

template <typename Comparable>
void select2(const vector<Comparable> &nums, int kthval){
	vector<int> temp_vec;
	temp_vec.reserve(kthval);
	for(int i=0;i<kthval;i++){
		temp_vec.push_back(nums[i]);
	}

	for(Comparable item:nums){
		auto min_of_tempvec = std::min_element(temp_vec.begin(),temp_vec.end());
		if (item>*min_of_tempvec){
			*min_of_tempvec = item;
		}
	}
	auto min_of_tempvec = std::min_element(temp_vec.begin(),temp_vec.end());
	cout<<"K th value is : "<<kthval<<endl;
	cout<<"Print the kth largest element"<<endl;
	cout<<kthval<<" th largest value in array --> "<<*min_of_tempvec<<endl;
}


#endif /* KTHLARGEST_H_ */
