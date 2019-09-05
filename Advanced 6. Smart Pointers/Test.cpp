#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"		//Point Line and Circle class all derived from Shape
#include "Array.h"
#include "ArrayException.h"	//Array template class and exception handle
#include "memory"
#include <iostream>
using namespace std;

//Point,Line,Circle derived from Shape class
//Point Line Circle Shape class: last version--level5 3.5 ex 5
//Array class using template method
//Array ArrayException class: last version--level 5 4.2a ex 1
//------change------
//create Shape pointer with ShapePtr
//which can automatically delete 
//constructor number= destructor number means memory automatically deleted

int main()
{
	// Typedef for a shared pointer to shape and
	// a typedef for an array with shapes stored as shared pointers.
	//typedef boost::shared_ptr<Shape> ShapePtr;
	//typedef Array<ShapePtr> ShapeArray;
	typedef shared_ptr<Shape> ShapePtr;
	typedef Array<ShapePtr> ShapeArray;

	try					//catch array out of bound error
	{
		//declare three Shape pointer
		ShapePtr p1;
		ShapePtr l1;
		ShapePtr c1;
		//print reference count which should be zero
		cout << "Point reference count " << p1.use_count() << endl;
		cout << "Line reference count " << l1.use_count() << endl;
		cout << "Circle reference count " << c1.use_count() << endl;
		{
			p1=ShapePtr(new Point(2.0, 4.5));				//create a Shape pointer to a Point
			l1=(ShapePtr) new Line(Point(1.0, 2.2), Point(2.3, 1.3));		//create a Shape pointer to a Line
			c1=(ShapePtr)(new Circle(Point(2.3, 0.2), 2.3));		//create a Shape pointer to a Circle

			//Print reference count
			cout << "Point reference count " << p1.use_count() << endl;
			cout << "Line reference count " << l1.use_count() << endl;
			cout << "Circle reference count " << c1.use_count() << endl;

			ShapeArray array1(3);				//create array of Shape pointer
			//assign value to array of Shape pointer
			array1[0] = p1;	
			array1[1] = l1;
			array1[2] = c1;

			//Print each Shape and reference count
			cout << "\nPoint: " << array1[0]->ToString() << endl;
			cout << "Point reference count " << p1.use_count() << endl;
			cout << "Line: " << array1[1]->ToString() << endl;
			cout << "Line reference count " << l1.use_count() << endl;
			cout << "Circle: " << array1[2]->ToString() << endl;
			cout << "Circle reference count " << c1.use_count() << endl;
		}
		
		//reference count change from 2 to 1 because array is released
		cout << "\nPoint reference count " << p1.use_count() << endl;
		cout << "Line reference count " << l1.use_count() << endl;
		cout << "Circle reference count " << c1.use_count() << endl;		
	}
	catch (ArrayException & ae) {						//catch error
		cout << ae.GetMessage() << endl;			//print error message
	}

	system("pause");
	return 0;
}
