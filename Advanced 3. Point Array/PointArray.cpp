#include "Array.h"
#include "Point.h"
#include "PointArray.h"
#include "ArrayException.h"

PointArray::PointArray()			//default constructor
	:Array<Point>::Array()
{
}

PointArray::PointArray(unsigned int size)			//constructor with a size argument
	:Array<Point>::Array(size)
{
}

PointArray::PointArray(const PointArray& source)		//copy constructor
	: Array<Point>::Array(source)
{
}

PointArray::~PointArray()								//destructor
{
}

PointArray& PointArray::operator=(const PointArray& source)		//assignment operator
{
	Array<Point>::operator=(source);
	return *this;
}

double PointArray::Length() const				//calculate length of array
{
	double lengthsum = 0.0;
	for (int i = 0; i < Size()-1; i++)					//stop when it is one point before last point.
	{
		lengthsum += (*this)[i].Distance((*this)[i+1]);		//distance between one point and next one.
	}
	return lengthsum;
}
