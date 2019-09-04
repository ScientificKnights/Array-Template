#ifndef ARRAYEXCEPTION_H
#define ARRAYEXCEPTION_H

#include <string>
#include <iostream>

//define the ArrayException base and derived class 
//which handles exception happens in Array class

class ArrayException
{
public:
	ArrayException() {};
	virtual std::string GetMessage() const = 0;		//return error message
	virtual ~ArrayException() {}
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
