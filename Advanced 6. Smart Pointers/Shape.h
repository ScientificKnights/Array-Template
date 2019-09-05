#ifndef SHAPE_H
#define SHAPE_H
#include <string>

//shape class which is base class for point,line and circle
//it has id number of different shapes

class Shape
{
private:
	int m_id;												// ID number
public:
	Shape();												//default constructor
	Shape(int);											//constructor with id numebr
	Shape(const Shape &sp);					//copy constructor
	virtual ~Shape();												//destructor
	Shape& operator = (const Shape& source);		// Assignment operator.
	virtual std::string ToString() const;					//conversion of shape to a string
	virtual void Draw() const = 0;						//Draw function
	void Print() const;								//Print function
	int ID();													// return ID number
};


#endif
