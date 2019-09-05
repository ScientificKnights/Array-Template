#define STACK_CPP
#include <iostream>
#include"Stack.h"
#include "StackException.h"

//realize all function of Stack

template<typename T>
Stack<T>::Stack()				//default constructor
	:m_array(Array<T>()), m_current(0)
{
}

template<typename T>
Stack<T>::Stack(unsigned int size)						//constructor with a size argument
	: m_array(Array<T>(size)), m_current(0)
{
}

template<typename T>
Stack<T>::Stack(const Stack<T>& source)			//copy constructor
	: m_array(source.m_array), m_current(source.m_current)
{
}

template<typename T>
Stack<T>::~Stack()		//destructor
{
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& source)//asignment operator
{
	if (this != &source)					//check self assignment
	{
		m_array = source.m_array;
		m_current = source.m_current;
	}

	return *this;
}

template<typename T>
void Stack<T>::Push(const T& add)      //add a new element to the array
{
	try		//try to catch out of bound error
	{
		m_array[m_current] = add;
		m_current++;
	}
	catch (OutOfBoundsException &ae)		//if out of bound,means array is full
	{
		throw StackFullException();			//throw a StackFullException exception
	}
}

template<typename T>
T Stack<T>::Pop()		//remove the last element of the array
{
	try
	{
		m_current--;
		return(m_array[m_current]);
	}
	catch (OutOfBoundsException & ae)		//if out of bound,means array is empty
	{
		m_current = 0;
		throw StackEmptyException();			//throw a StackEmptyException exception
	}
}

template<typename T>
unsigned int Stack<T>::Current() const
{
	return m_current;
}
