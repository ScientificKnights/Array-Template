#ifndef NUMERICARRAY_H
#define NUMERICARRAY_H

#include "Array.h"

template<typename T>
class NumericArray :public Array<T> {
public:
	NumericArray();					//default constructor
	NumericArray(unsigned int size);		//constructor with a size argument
	NumericArray(const NumericArray<T> &source);		//copy constructor
	virtual ~NumericArray();				//destructor
	NumericArray<T>& operator=(const NumericArray<T> & source);			//assignment operator
	NumericArray<T> operator + (const NumericArray<T>& p) const;		// Add two arrays.
	NumericArray<T> operator*(double factor) const;								//Scale array.
	double DotProduct(const NumericArray<T>& array2) const;				//dot product
};

#ifndef NUMERICARRAY_CPP
#include "NumericArray.cpp"
#endif

#endif
