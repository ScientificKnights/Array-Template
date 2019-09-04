#include "Point.h"
#include <iostream>
using namespace std;
//goal: test dynamiclly create object

int main(){
	double x, y;
	cout << "Please input x and y for point A, separate with space" << endl;
	cin >> x >> y;			//get x and y from user

	Point *point1 = new Point;	//default constructor
	Point *point2 = new Point(x, y);//constructor with coordinates
	Point *point3 = new Point(*point2);// copy constructor
	*point1 = *point3;//assign to pointer variables


	cout << "pointer 1: " << *point1 << " distance to origin: " << point1->Distance() << endl;
	cout << "pointer 2: " << *point2 << " distance to origin: " << (*point2).Distance() << endl;
	cout << "pointer 3: " << *point3 << " distance to origin: " << (*point3).Distance() << endl;

	delete point1;
	delete point2;
	delete point3;

	int i; //size of array
	cout << "Please enter the size of array:";
	cin >> i;

	//Point ps[i];
	//try to create an array on the stack using the entered size. 
	//compiler error
	Point *ps = new Point [i];
	for (int j = 0; j < i; j++)	//print points{
		cout << "Point " << j+1 << "=" << ps[j] << endl;
	}

	delete [] ps;

	system("pause");
	return 0;
}
