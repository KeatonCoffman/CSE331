// Author: Keaton Coffman
// Professor Onsay
// CSE 331
// File: myminstack.h
//

#ifndef myminstack_h
#define myminstack_h

#include "mystack.h"



template<typename T>
class minstack {
	private:
		MyStack<T> main_stack;
		MyStack<T> min_stack;
	public:
		void push(T val);
		void pop();
		T gettop();
		T getMin();
};

// Function: Push a value onto the main and or the min stack
// Pre: Minstack has been intitialized
// Post: If minstack is empty or val is less than the top of midstack push onto minstack otherwise push onto main stack
template<typename T>
void minstack<T>::push(T val) {
	if ( min_stack.empty() || val <= min_stack.getTop()){
		min_stack.push(val);
	}
	main_stack.push(val);
}

// Function: Pop the value from the min and or main stack
// Pre: Minstack has been intitialized
// Post: If the top of main and min stack are the same pop minstack otherwise pop main stack
template<typename T>
void minstack<T>::pop() {
	if (main_stack.getTop() == min_stack.getTop()){
		min_stack.pop();
	}
	main_stack.pop();
}

// Function: Get the top of main stack
// Pre: Minstack has been intitialized
// Post: Returns top of main stack
template<typename T>
T minstack<T>::gettop() {
	return main_stack.getTop();
}

// Function: Get top of minstack
// Pre: Minstack has been intitialized
// Post: Return top of min stack
template<typename T>
T minstack<T>::getMin() {
	return min_stack.getTop();
};

#endif
