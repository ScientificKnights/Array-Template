#define NUMERICARRAY_CPP
#include "Array.h"
#include "ArrayException.h"
#include "NumericArray.h"

//Define NumericArray which is derived class of Array class
//in NumericArray class, it defines numeric function like sum, scale and dot product.

template<typename T>
NumericArray<T>::NumericArray()				//default constructor
	: Array<T>::Array()
{
	//Array<T>::Array();
}

template<typename T>
NumericArray<T>::NumericArray(unsigned int size)			//constructor with a size argument
	:Array<T>::Array(size)
{
	//Array<T>::Array(size);
}

template<typename T>
NumericArray<T>::NumericArray(const NumericArray<T>& source)	//copy constructor
	:Array<T>::Array(source)
{
	//Array<T>::Array(source);
}

template<typename T>
NumericArray<T>::~NumericArray()			//destructor
{
	//Array<T>::~Array();	call base destructor automatically. don't call twice
}


template<typename T>
NumericArray<T>& NumericArray<T>::operator=(const NumericArray<T>& source)		//assignment operator
{
	Array<T>::operator=(source);
	return *this;
}

template<typename T>
NumericArray<T> NumericArray<T>::operator+(const NumericArray<T>& p) const	// Add two arrays.
{
	if (Size() != p.Size() ) throw ArraySizeException();	//two array different size
	NumericArray<T> arraysum(Size());		//same size array store the sum result
	for (int i = 0; i < Size(); i++)		//sum each T object
		arraysum[i] = p[i] + (*this)[i];
	return arraysum;
}

template<typename T>
NumericArray<T> NumericArray<T>::operator*(double factor) const					//Scale array.
{
	NumericArray<T> arrayscale(Size());
	for (int i = 0; i < Size(); i++)		//each T object multiply factor
		arrayscale[i] = factor*(*this)[i];
	return arrayscale;
}

template<typename T>
double NumericArray<T>::DotProduct(const NumericArray<T>& array2) const			//dot product
{
	if (Size() != array2.Size()) throw ArraySizeException();	//two array different size
	double dotproductresult=0.0;
	for (int i = 0; i < Size(); i++)		//each T object multiply factor
		dotproductresult += array2[i]*(*this)[i];
	return dotproductresult;
}
