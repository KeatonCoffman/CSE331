/*
 * LinearSearch.h
 *
 *  Created on: Today
 *      Author: onsayse
 */
#ifndef LINEARSEARCH_H_
#define LINEARSEARCH_H_
#include <vector>
using namespace std;
template <typename Comparable>
/**
 * @pre: array(vector) is non empty
 * @return bool
 * @post: the value returned true if found false otherwise
 */
//your code goes here!
bool linearSearch(vector<Comparable> &items, const int key){
  for (auto item:items){
    if (item==key){
	  return true;
	}
   };
   return false;
}
#endif /* LINEARSEARCH_H_ */
