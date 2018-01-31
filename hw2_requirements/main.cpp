/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: onsayse
 *
 * Created on September 15, 2016, 9:35 AM
 */

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
#include <random>
#include "SearchSort.h"
using namespace std;

bool isSorted(vector<int> A);
bool isSortedDec(vector<int> A);
int main() {
	/* read from file
	 *
	 */
	ifstream inClientFile("input_real_small.in",ios::in);
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
        cout<<"The vector is "<< nums[2];


    //TESTING INSERTION SORT
   cout<<"++++++++++++++++++++++++++++++++++"<<endl;
   cout<<"TESTING INSERTION SORT " << endl;
	auto t1 = std::chrono::high_resolution_clock::now();
	srand(static_cast<unsigned int>(time(0)));
	//sort array in ascending order
		cout<<"Before insert sort"<< endl;
	//uncomment the line below when testing
       // simpleprint(nums);
	//cout<<endl;
	//cout<<endl;
	//uncomment the line below when testing
        insertion_sort(nums);
		//	cout<<"After"<< endl;
			//simpleprint(nums);
	auto t2 = std::chrono::high_resolution_clock::now();
	cout << "Size of the vector : "<< nums.size() << endl;
	cout << "Insertion Sort method  took "
			<< std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
			<< " nanoseconds \n";
	cout<<endl;
	if (isSorted(nums))
		cout<<"The vector is sorted" << endl;
	else
		cout<<"The vector is not sorted" << endl;



	//TESTING INSERTION SORT DESCENDING ORDER..
	//insertion sort in descending order
   cout<<"++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"TESTING INSERTION SORT IN DESCENDING ORDER " << endl;
	auto t3 = std::chrono::high_resolution_clock::now();
	srand(static_cast<unsigned int>(time(0)));
	
		cout<<"Before insert sort"<< endl;
	//uncomment the line below when testing
        simpleprint(nums);
	cout<<endl;
	cout<<endl;
	//uncomment the line below when testing
        insert_sort_dec(nums);
			cout<<"After"<< endl;
			simpleprint(nums);

	//uncomment the line below when testing
        insert_sort_dec(nums);
	auto t4 = std::chrono::high_resolution_clock::now();
	cout << "Size of the vector : "<< nums.size() << endl;
	cout << "Insertion Sort Descending Order method  took "
			<< std::chrono::duration_cast<std::chrono::nanoseconds>(t4-t3).count()
			<< " nanoseconds \n";    inClientFile.close();
	cout<<endl;

	if (isSortedDec(nums))
		cout<<"The vector is sorted in descending order" << endl;
	else
		cout<<"The vector is not sorted in descending order" << endl;

}
/*
 * @params: vector
 * @return:bool
 */
bool isSorted(vector<int> A)
{
	for(auto i=0; i<A.size()-1; i++)
	{
		if (!(A[i+1] > A[i]))
			return false;

	}
	return true;

}


bool isSortedDec(vector<int> A)
{
	for(auto i=0; i<A.size()-1; i++)
	{
		if (!(A[i+1] < A[i]))
			return false;

	}
	return true;

}
