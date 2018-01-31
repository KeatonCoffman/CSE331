// Author: Keaton Coffman
// Professor Onsay
// CSE 331
// File: mystack.h
//


#ifndef mystack_h
#define mystack_h

#include <vector>
#include <stdexcept>
#include <string>
using namespace std;

// following code segment is generated from Lecture 6 slide 24
template<typename T>
class MyStack {
	protected:
		int size_of_stack;
		int vec_capacity;
		vector<T> vec_stack;
	public:
		MyStack(int n = 25);
		~MyStack() = default;
		void push(T const & val);
		void pop();
		void display();
		T getTop();
		bool empty();
		T front();
		void que_pop();
};

// Pre: Overflow Subclass
// Post: Throws error and prints string "n"
class overflow: public std::runtime_error {
	public:
		explicit overflow(string n): std::runtime_error(n){};
};

// Pre: Underflow Subclass
// Post: Throws error and prints string "n"
class underflow: public std::runtime_error {
	public:
		explicit underflow(string n): std::runtime_error(n){};
};


// Class Constructor
template<typename T>
MyStack<T>::MyStack(int n) {
	size_of_stack = 0;
	vec_capacity = n;
}

// Function: Adds item to back of stack
// Pre: Stack has been intitialized
// Post: If stack is full throw overflow else val is pushed onto stack and size of stack is increased
template<typename T>
void MyStack<T>::push(T const & val) {
	if (size_of_stack == vec_capacity) {
		throw overflow("Push in MyStack threw an overflow error");
	}
	vec_stack.push_back(val);
	++size_of_stack;
}

// Function: Take the top item off the stack 
// Pre: Stack has been intitialized
// Post: If stack is empty throw underflow else remove top item off stack
template<typename T>
void MyStack<T>::pop() {
	if (empty()) {
		throw underflow("Pop in MyStack threw an underflow error");
	}
	vec_stack.pop_back();
	--size_of_stack;
}

template<typename T>
void MyStack<T>::display() {
	int i;
	for(i=size_of_stack-1;i>=0;i--){
		cout<<i+1<<": "<<vec_stack[i]<<endl;
	}
}

// Function: Gives top of stack
// Pre: Stack has been intitialized
// Post: If stack is empty throw exception else return top of stack
template<typename T>
T MyStack<T>::getTop() {
	if (empty()) {
		throw underflow("getTop in MyStack threw an underflow error");
	}
	return vec_stack[size_of_stack - 1];
}

// Function: Check if your vector is empty
// Pre: Stack has been initialized
// Post: return true or false depending on size of stack
template<typename T>
bool MyStack<T>::empty() {
	return ( vec_stack.size() == 0);
};

// Function: Access the front of the vector
// Pre: Stack has been initialized
// Post: returns the front of the vector
template<typename T>
T MyStack<T>::front() {
	return vec_stack[0];
}

// Function: Pop the front of a que
// Pre: Stack has been initialized
// Post: Erases the first item in the queue
template<typename T>
void MyStack<T>::que_pop() {
	vec_stack.erase(vec_stack.begin(),vec_stack.begin()+1);
}


#endif
