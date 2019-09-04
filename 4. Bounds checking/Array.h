#ifndef ARRAY_H
#define ARRAY_H
#include "Point.h"

//Array class: handle memory of array of Point class
//get array size
//set and get array element

class Array {
private:
	unsigned int m_size;			//size of the array
	Point *m_data;		//for a dynamic C array of Point objects
public:
	Array();					//default constructor that allocates for example 10 elements
	Array(unsigned int size);		//constructor with a size argument
	Array(const Array &ay);		//copy constructor
	~Array();				//destructor
	Array& operator=(const Array & source);			//assignment operator
	unsigned int Size() const;				//returns the size of the array
	void SetElement(unsigned int index, const Point &newpoint);			//sets an element
	Point GetElement(unsigned int index) const;		//return the element by reference
	Point& operator [] (unsigned int index);							//square bracket operator
	const Point& operator [] (unsigned int index) const;		//const version square bracket operator
};

#endif
