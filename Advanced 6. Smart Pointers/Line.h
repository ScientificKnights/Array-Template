#ifndef LINE_H
#define LINE_H
#include <string>
#include "Point.h"
#include "Shape.h"

//line class
//Line class have two Point objects as data members
//calculate length and describe line

class Line :public Shape
{
private:
	Point startpoint;
	Point endpoint;
public:
	Line();						//default constructor
	Line(Point newstartpt, Point newendpt);		//constructor accepts two Points
	Line(int id, Point newstartpt, Point newendpt);		//constructor accepts id and two Points
	Line(const Line &line);						//copy constructor
	virtual ~Line();					//destructor
	Point P1() const;		//get two points
	Point P2() const;
	void P1(const Point &newstartpt);		//set two points
	void P2(const Point &newendpt);
	virtual std::string ToString() const;					//conversion of the two points to a string
	double Length() const;						//calculate length
	virtual void Draw() const;							//Draw function
	Line& operator = (const Line& source);		// Assignment operator.
	friend std::ostream& operator << (std::ostream& os, const Line& l); // Send to ostream.
};

#endif
