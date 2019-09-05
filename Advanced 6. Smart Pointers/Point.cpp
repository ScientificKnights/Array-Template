#include "Point.h"
#include "Shape.h"
#include <sstream>
#include <iostream>
#include <cmath>
using namespace std;

//realize Point class

Point::Point()			//default constructor
	:Shape(), m_x(0.0), m_y(0.0)
{
	//	m_x = 0.0;
	//	m_y = 0.0;
	cout << "Point default constructor!" << endl;
}

Point::Point(const Point & pt)				//copy constructor
	:Shape(pt), m_x(pt.m_x), m_y(pt.m_y)
{
	//m_x = pt.m_x;
	//m_y = pt.m_y;
	cout << "Point copy constructor!" << endl;
}

Point::Point(double new_x, double new_y)		//constructor accepts x and y
	:Shape(), m_x(new_x), m_y(new_y)
{
	//	m_x = new_x;
	//	m_y = new_y;
	cout << "Point constructor that accepts x and y coordiantes!" << endl;
}

Point::Point(int id, double new_x, double new_y)	//constructor accepts id, x and y
	:Shape(id), m_x(new_x), m_y(new_y)
{
}

Point::~Point()			//destructor
{
	cout << "Bye my points." << endl;
}

double Point::X() const		//get x and y coordinates
{
	return m_x;
}

double Point::Y() const
{
	return m_y;
}

void Point::X(double new_x)		//set x and y coordinates
{
	m_x = new_x;
}

void Point::Y(double new_y)
{
	m_y = new_y;
}


std::string Point::ToString() const		//conversion of the double coordinates to a string
{
	std::string s = Shape::ToString();
	std::stringstream ss;
	ss << "Point(" << m_x << ", " << m_y << ") " << s;		//convert to string
	return ss.str();															//return string
}


double Point::Distance() const		 // Calculate the distance to the origin (0, 0).
{
	return std::sqrt(pow(m_x, 2) + pow(m_y, 2));
}

double Point::Distance(const Point & p) const		// Calculate the distance between two points.
{
	return std::sqrt(pow((m_x - p.m_x), 2) + pow((m_y - p.m_y), 2));
}

void Point::Draw() const
{
	cout << "Draw Point;" << endl;
}

Point Point::operator-() const				// Negate the coordinates.
{
	return Point(-m_x, -m_y);
}

Point Point::operator*(double factor) const			// Scale the coordinates.
{
	return Point(m_x*factor, m_y*factor);
}

Point Point::operator+(const Point & p) const		// Add coordinates.
{
	return Point(m_x + p.m_x, m_y + p.m_y);
}

bool Point::operator==(const Point & p) const		// Equally compare operator.
{
	return ((m_x == p.m_x) && (m_y == p.m_y)) ? true : false;
}

Point & Point::operator=(const Point & source)		// Assignment operator.
{
	//cout << "Point assignment operator!" << endl;
	if (&source != this)			//preclude self assignment
	{
		Shape::operator=(source);
		m_x = source.m_x;
		m_y = source.m_y;
	}
	return *this;
}

Point & Point::operator*=(double factor)				// Scale the coordinates & assign.
{
	m_x *= factor;
	m_y *= factor;
	return *this;
}

std::ostream& operator << (std::ostream& os, const Point& p) // Send to ostream.
{
	os << "Point(" << p.m_x << ", " << p.m_y << ")";
	return os;
}
