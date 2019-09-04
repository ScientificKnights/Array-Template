#define Array_cpp
#include "Array.h"
#include "ArrayException.h"

//Array<T> class: handle memory of array of T class
//get array size
//set and get array element
//Array<T> class is a template of type T

template<typename T>
Array<T>::Array()					//default constructor that allocates for 10 elements
	:m_data(new T[5]), m_size(5) {
}

template<typename T>
Array<T>::Array(unsigned int size)		//constructor with a size argument
	:m_data(new T[size]), m_size(size) {
}

template<typename T>
Array<T>::Array(const Array<T> &ay) {	//copy constructor
	m_size = ay.m_size;						//copy size
	m_data = new T[m_size];
	for (int i = 0; i < m_size; i++)		//copy each T object
		m_data[i] = ay.m_data[i];		//both will run
										//*(m_data + i) = *(ay.m_data + i);
}

template<typename T>
Array<T>::~Array() {				//destructor
	delete[] m_data;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T> & source) {		//define assignment
	if (this == &source)
		return *this;
	delete[] m_data;							//delete old memory
	m_size = source.m_size;				//copy size
	m_data = new T[m_size];
	for (int i = 0; i < m_size; i++)		//copy each T object
		m_data[i] = source.m_data[i];
	return *this;
}

template<typename T>
unsigned int Array<T>::Size() const {			//returns the size of the array
	return m_size;
}

template<typename T>
void Array<T>::SetElement(unsigned int index, const T & newT)	{		//sets an element
	if (index >= m_size) throw OutOfBoundsException(index);		//Outside bounds
	m_data[index] = newT;				//Ok now
}

template<typename T>
T Array<T>::GetElement(unsigned int index) const {	//return the element by reference
	if (index >= m_size) throw OutOfBoundsException(index);		//Outside bounds
	return m_data[index];						//Ok now
}

template<typename T>
T & Array<T>::operator[](unsigned int index) {						//square bracket operator
	if (index >= m_size) throw OutOfBoundsException(index);		//Outside bounds
	return m_data[index];						//Ok now
}

template<typename T>
const T & Array<T>::operator[](unsigned int index) const {		//const version square bracket operator
	if (index >= m_size) throw OutOfBoundsException(index);		//Outside bounds
	return m_data[index];						//Ok now
}
