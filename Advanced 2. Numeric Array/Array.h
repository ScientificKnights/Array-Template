#ifndef ARRAY_H
#define ARRAY_H

//Array<T> class: handle memory of array of T class
//get array size
//set and get array element
//Array<T> class is a template of type T

template<typename T>
class Array
{
private:
	unsigned int m_size;			//size of the array
	T *m_data;		//for a dynamic C array of T objects
public:
	Array();					//default constructor that allocates for example 10 elements
	Array(unsigned int size);		//constructor with a size argument
	Array(const Array<T> &ay);		//copy constructor
	virtual ~Array();				//destructor
	Array<T>& operator=(const Array<T> & source);			//assignment operator
	unsigned int Size() const;				//returns the size of the array
	void SetElement(unsigned int index, const T &newT);			//sets an element
	T GetElement(unsigned int index) const;		//return the element by reference
	T& operator [] (unsigned int index);							//square bracket operator
	const T& operator [] (unsigned int index) const;		//const version square bracket operator
};

#ifndef Array_cpp // Must be the same name as in source file #define
#include "Array.cpp"		
//i think the reason it still works is we include Array.cpp in Array.h
//so if we include Array.h in test file, we will include both.
#endif

#endif
