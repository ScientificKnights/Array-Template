#ifndef POINTARRAY_H
#define POINTARRAY_H

#include "Array.h"
#include "Point.h"

class PointArray :public Array<Point>		//no need template <typename T>
{
public:
	PointArray();									//default constructor
	PointArray(unsigned int size);			//constructor with a size argument
	PointArray(const PointArray &source);		//copy constructor
	virtual ~PointArray();						//destructor
	PointArray& operator=(const PointArray & source);			//assignment operator
	double Length() const;					//calculate length of array
};

#endif


