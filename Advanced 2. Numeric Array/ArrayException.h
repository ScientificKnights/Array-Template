#ifndef ARRAYEXCEPTION_H
#define ARRAYEXCEPTION_H

#include <string>
#include <iostream>

//define the ArrayException base and derived class 
//which handles exception happens in Array class
//ArraySizeException handles when two arrays have different size
//OutOfBoundsException handles read and write object out of array size

class ArrayException
{
public:
	ArrayException() {};
	virtual std::string GetMessage() const = 0		//return error message
	{
		return "Array Exception!!!";
	}
	virtual ~ArrayException() {}
};

class ArraySizeException :public ArrayException	//sum or dotproduct two arrays of different size
{
public:
	ArraySizeException(){}									//default constructor
	virtual std::string GetMessage() const			//return error message
	{
		return "Two arrays have different size Exception!!!";
	}
	virtual ~ArraySizeException() {}
};

class OutOfBoundsException :public ArrayException
{
private:
	int m_index;			//index which is out of bounds
public:
	OutOfBoundsException() {}
	OutOfBoundsException(int index) { m_index = index; }		//constructor with index
	virtual std::string GetMessage() const			//return error message
	{
		return "Array Out Of Bounds Exception!!!";
	}
	virtual ~OutOfBoundsException() {}
};

#endif

