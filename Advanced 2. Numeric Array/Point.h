#ifndef POINT_H
#define POINT_H
#include <iostream>

//Point class
//contains x and y coordinates and function to set and show x and y 
//and describe the point by with string.
//and calculate distance between origin and other point

class Point
{
private:
	double m_x; //x coordinate
	double m_y;//y coordinate
public:
	Point();												//default constructor
	Point(const Point &pt);							//copy constructor
	Point(double new_x, double new_y);		//constructor accepts x and y
	~Point();											//destructor
	double X() const;								//get x and y coordinates
	double Y() const;
	void X(double new_x);						//set x and y coordinates
	void Y(double new_y);
	double Distance() const;					// Calculate the distance to the origin (0, 0).
	double Distance(const Point & p) const;		// Calculate the distance between two points.
	Point operator - () const;					// Negate the coordinates.
	Point operator * (double factor) const;			// Scale the coordinates.
	double operator * (const Point & p) const;		//dot product of points
	Point operator + (const Point& p) const;		// Add coordinates.
	bool operator == (const Point& p) const;		// Equally compare operator.
	Point& operator = (const Point& source);		// Assignment operator.
	Point& operator *= (double factor);				// Scale the coordinates & assign.
	friend std::ostream& operator << (std::ostream& os, const Point& p); // Send to ostream.
};

#endif
