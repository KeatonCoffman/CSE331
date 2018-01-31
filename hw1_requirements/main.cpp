//============================================================================
// Name        : main.cpp
// Author      : Sebnem Onsay
// Version     :
// Copyright   : Your copyright notice
// Description : Homework1
//============================================================================

#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
#include <random>
#include "KthLargest.h"
#include <chrono>
using namespace std;

int main()
{
	//cout<<"In"<<endl;
	//ifstream inClientFile("input_real_small",ios::in);
	ifstream inClientFile("input.in",ios::in);
	// check to see if file opening succeeded

	if ( !inClientFile.is_open() ) {
		cout<<"Could not open file\n";
		return 0;
	}
	vector<int> nums;

	int input_t;
	while( inClientFile >> input_t) {
		nums.push_back(input_t);
	}

	//Testing Hw1 using Bubble sort returning the largest element
	auto t1 = std::chrono::high_resolution_clock::now();
	srand(static_cast<unsigned int>(time(0)));
	//sort array in ascending order, return the last element
	//Generate random k values
	int min=1,max=10;

	random_device rd;     // only used once to initialize (seed) engine
	mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	uniform_int_distribution<int> uni(min,2000); // guaranteed unbiased
	auto kthvalue = uni(rng);


	select1(nums,kthvalue);
	auto t2 = std::chrono::high_resolution_clock::now();
	cout << "Size of the vector : "<< nums.size() << endl;
	cout << "Bubble Search method  took "
			<< std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
			<< " milliseconds \n";    inClientFile.close();
	cout<<endl;

	//Testing Hw1 using temparray approach, sort returning the largest element
	auto t3 = std::chrono::high_resolution_clock::now();
	srand(static_cast<unsigned int>(time(0)));
	select2(nums,kthvalue);
	auto t4 = std::chrono::high_resolution_clock::now();


	cout << "Size of the vector : "<< nums.size() << endl;
	cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t4-t3).count()
			<< " nanoseconds \n";    inClientFile.close();

	//Testing for different data sizes...
	//For this part of your hw you are allowed to modify your main method...
	//your code goes here....


	return 0;


}


