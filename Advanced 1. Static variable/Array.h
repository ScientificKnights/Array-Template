#ifndef ARRAY_H
#define ARRAY_H

//Array<T> class: handle memory of array of T class
//get array size
//set and get array element
//Array<T> class is a template of type T

template<typename T>
class Array {
private:
	unsigned int m_size;					//size of the array
	static unsigned int m_size_default;			//default size of the array
	T *m_data;		//for a dynamic C array of T objects
public:
	Array();					//default constructor that allocates for example 10 elements
	Array(unsigned int size);		//constructor with a size argument
	Array(const Array<T> &ay);		//copy constructor
	~Array();				//destructor
	Array<T>& operator=(const Array<T> & source);			//assignment operator
	unsigned int Size() const;				//returns the size of the array
	static unsigned int DefaultSize();		//returns the default size of the array
	static void DefaultSize(unsigned int new_size);		//reset the default size of the array
	void SetElement(unsigned int index, const T &newpoint);			//sets an element
	T GetElement(unsigned int index) const;		//return the element by reference
	T& operator [] (unsigned int index);							//square bracket operator
	const T& operator [] (unsigned int index) const;		//const version square bracket operator
};

#ifndef Array_cpp 
#include "Array.cpp"		
#endif

#endif
