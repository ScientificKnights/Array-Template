#define _USE_MATH_DEFINES
#include <cmath>		//for pi
#include "Circle.h"
#include "Point.h"
#include "Shape.h"
#include <iostream>
#include <sstream>
using namespace std;

//realize Circle class

Circle::Circle()		//default constructor
	:Shape(), center(0.0, 0.0), m_radius(1.0)
{
	//center = Point(0.0, 0.0);	//set center to (0,0)
	//m_radius = 1.0;				//set radius to 1.0
	cout << "Circle default constructor!" << endl;
}

Circle::Circle(Point newcenter, double newradius)		//constructor accepts center and radius
	:Shape(), center(newcenter), m_radius(newradius)
{
	//center = newcenter;
	//m_radius = newradius;
	cout << "Circle constructor accepts center and radius!" << endl;
}

Circle::Circle(int id, Point newcenter, double newradius)	//constructors accepts id, center and radius
	:Shape(id), center(newcenter), m_radius(newradius)
{
}

Circle::Circle(const Circle & newcircle)						//copy constructor
	: Shape(newcircle), center(newcircle.center), m_radius(newcircle.m_radius)
{
	//center = newcircle.center;
	//m_radius = newcircle.m_radius;
	cout << "Circle copy constructor!" << endl;
}

Circle::~Circle()			//destructor
{
	cout << "Bye Circle." << endl;
}

Point Circle::CenterPoint() const						//get center point
{
	return center;
}

double Circle::Radius() const							//get radius
{
	return m_radius;
}

void Circle::CenterPoint(const Point &newcenter)			//set center point
{
	center = newcenter;
}

void Circle::Radius(const double &newradius)					//set radius
{
	m_radius = newradius;
}

std::string Circle::ToString() const				//conversion center and radius to a string
{
	std::string s = Shape::ToString();
	std::stringstream ss;
	ss << "Center: Point(" << center.X() << ", " << center.Y() << ") Radius:" << m_radius << " " << s;		//convert to string
	return ss.str();											//return string
}

double Circle::Diameter() const					//calculate diameter
{
	return m_radius*2.0;
}

double Circle::Area() const							//calculate area
{
	return M_PI*m_radius*m_radius;
}

double Circle::Circumference() const			//calculate circumference
{
	return M_PI*m_radius * 2;
}

void Circle::Draw() const
{
	cout << "Draw Circle;" << endl;
}

Circle & Circle::operator=(const Circle & source)		// Assignment operator.
{
	//cout << "Circle assignment operator!" << endl;
	if (&source != this)			//preclude self assignment
	{
		Shape::operator=(source);
		center = source.center;
		m_radius = source.m_radius;
	}
	return *this;
}

std::ostream& operator << (std::ostream& os, const Circle& c) // Send to ostream.
{
	os << "center: " << c.center << " radius:" << c.m_radius;
	return os;
}
