#include "Line.h"
#include "Point.h"
#include "Shape.h"
#include <iostream>
#include <sstream>
using namespace std;

//realize Line class

Line::Line()		//default constructor
	: Shape(), startpoint(0.0, 0.0), endpoint(0.0, 0.0)
{
	//startpoint = Point(0.0, 0.0);	//set points to (0,0)
	//endpoint = Point(0.0, 0.0);
	cout << "Line default constructor!" << endl;
}

Line::Line(Point newstartpt, Point newendpt)	//constructor accepts two Points
	: Shape(), startpoint(newstartpt), endpoint(newendpt)
{
	//startpoint = newstartpt;
	//endpoint = newendpt;
	cout << "Line constructor accepts two Points!" << endl;
}

Line::Line(int id, Point newstartpt, Point newendpt)	//constructor accepts id and two Points
	: Shape(id), startpoint(newstartpt), endpoint(newendpt)
{
}

Line::Line(const Line & line)						//copy constructor
	: Shape(line), startpoint(line.startpoint), endpoint(line.endpoint)
{
	//startpoint = line.startpoint;
	//endpoint = line.endpoint;
	cout << "Line copy constructor!" << endl;
}

Line::~Line()			//destructor
{
	cout << "Bye Line." << endl;
}

Point Line::P1() const		//get two points
{
	return startpoint;
}

Point Line::P2() const
{
	return endpoint;
}

void Line::P1(const Point &newstartpt)		//set two points
{
	startpoint = newstartpt;
}

void Line::P2(const Point & newendpt)
{
	endpoint = newendpt;
}


std::string Line::ToString() const				//conversion of the two points to a string
{
	std::string s = Shape::ToString();
	std::stringstream ss;
	ss << "Startpoint: (" << startpoint.X() << ", " << startpoint.Y() << ")"
		<< " Endpoint:(" << endpoint.X() << ", " << endpoint.Y() << ") " << s;		//convert to string
	return ss.str();															//return string
}


double Line::Length() const					//calculate length
{
	return startpoint.Distance(endpoint);
}

void Line::Draw() const
{
	cout << "Draw Line;" << endl;
}

Line & Line::operator=(const Line & source)		// Assignment operator.
{
	//cout << "Line assignment operator!" << endl;
	if (&source != this)			//preclude self assignment	
	{
		Shape::operator=(source);
		startpoint = source.startpoint;
		endpoint = source.endpoint;
	}
	return *this;
}

std::ostream& operator << (std::ostream& os, const Line& l) // Send to ostream.
{
	os << "startpoint: (" << l.startpoint.X() << ", " << l.startpoint.Y() << ")"
		<< " endpoint:(" << l.endpoint.X() << ", " << l.endpoint.Y() << ")";
	return os;
}
