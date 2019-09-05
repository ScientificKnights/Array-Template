#include "Shape.h"
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <iostream>
using namespace std;

//shape class which is base class for point,line and circle
//it has id number of different shapes

Shape::Shape()												//default constructor
	:m_id(rand())
{
//	m_id = rand();
	cout << "Shape default constructor!" << endl;
}

Shape::Shape(int id)											//constructor with id numebr
	:m_id(id)
{
//	m_id = id;
	cout << "Shape constructor accepts id !" << endl;
}

Shape::Shape(const Shape & sp)					//copy constructor
	:m_id(sp.m_id)
{
//	m_id = sp.m_id;
	cout << "Shape copy constructor!" << endl;
}

Shape::~Shape()
{
	cout << "Bye Shape." << endl;
}

Shape & Shape::operator=(const Shape & source)		// Assignment operator.
{
	if (&source != this)			//preclude self assignment
	{
		m_id = source.m_id;
	}
	return *this;
}

std::string Shape::ToString() const				//conversion of shape to a string
{
	std::stringstream ss;
	ss << "ID: " << m_id;		//convert to string
	return ss.str();					//return string
}

void Shape::Print() const
{
	cout << ToString() << endl;
}

int Shape::ID()						//return ID number
{
	return m_id;
}
