#ifndef STACK_H
#define STACK_H

#include"Array.h"

//delegate store data function to Array class
//have pop and push function

template<typename T>
class Stack {
private:
	unsigned int m_current;
	Array<T> m_array;

public:
	Stack();												//default constructor
	Stack(unsigned int size);                //constructor with a size argument
	Stack(const Stack<T>& source);   //copy constructor
	~Stack();										//destructor
	Stack<T>& operator=(const Stack<T>& source);//assignment operator
	void Push(const T& add);        //add a new element to the array
	T Pop();									//remove the last element of the array
	unsigned int Current() const;					//return current number in Stack
};

#ifndef STACK_CPP
#include"Stack.cpp"
#endif

#endif
