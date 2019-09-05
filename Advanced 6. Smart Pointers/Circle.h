#ifndef CIRCLE_H
#define CIRCLE_H
#include <string>
#include "Point.h"
#include "Shape.h"

//Circle class
//Circle class have one Point object and radius as data members
//calculate diameter, area, circumference and describe circle with string

class Circle :public Shape
{
private:
	Point center;
	double m_radius;
public:
	Circle();						//default constructor
	Circle(Point newcenter, double newradius);				//constructor accepts center and radius
	Circle(int id, Point newcenter, double newradius);		//constructors accepts id, center and radius
	Circle(const Circle &newcircle);									//copy constructor
	virtual ~Circle();					//destructor
	Point CenterPoint() const;		//get center point
	double Radius() const;		//get radius
	void CenterPoint(const Point &newcenter);		//set center point
	void Radius(const double &newradius);		//set radius
	virtual std::string ToString() const;					//conversion center point and radius to a string
	double Diameter() const;						//calculate diameter
	double Area() const;								//calculate area
	double Circumference() const;				//calculate circumference
	virtual void Draw() const;						//Draw function
	Circle& operator = (const Circle& source);		// Assignment operator.
	friend std::ostream& operator << (std::ostream& os, const Circle& c); // Send to ostream.
};

#endif
