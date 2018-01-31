// Author: Keaton Coffman
// Professor Onsay
// CSE 331
// File: myqueue.h
//
//

#ifndef myqueue_h
#define myqueue_h

#include "mystack.h"


template<typename T>
class myqueue {
	private:
		int front;
		int back;
		MyStack<T> queue_stack;
	public:
		void push(T val);
		void pop();
		T gettop();
		bool empty();
};

// Function: Push a value onto the queue
// Pre: Queue has been initialized
// Post: val is pushed onto the back of the stack
template<typename T>
void myqueue<T>::push(T val) {
	queue_stack.push(val);
	++back;
}

// Function: Pop the front of the queue
// Pre: Queue has been initialized
// Post: If the queue is empty print otherwise front of the queue is popped
template<typename T>
void myqueue<T>::pop() {
	if(empty()){
		cout<<"Queue is Empty"<<endl;
	}
	queue_stack.que_pop();
}

// Function: Get the top of the queue
// Pre: Queue has been initialized
// Post: If the queue is empty print to user otherwise return front of queue
template<typename T>
T myqueue<T>::gettop() {
	if(empty()){
		cout<<"Queue is Empty"<<endl;
	}
	return queue_stack.front();
}

// Function: Boolean returning whether the queue is empty or not
// Pre: Queue has been initialized
// Post: return a boolean for if the queue is empty or not
template<typename T>
bool myqueue<T>::empty() {
	return (queue_stack.empty());
};



#endif
