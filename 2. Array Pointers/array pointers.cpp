#include "Point.h"
#include <iostream>
using namespace std;
//goal: create array of pointers

int main() {
	Point** ps = new Point*[3];		//array of pointers
	ps[0] = new Point;					//default constructor
	ps[1] = new Point(1, 2);			//constructor with coordinates
	ps[2] = new Point(*ps[1]);		//copy constructor

	for (int i = 0; i < 3; i++)	{   //print points
		cout << "Point " << i+1 << "=" << *ps[i] << endl;
	}
	for (int i = 0; i < 3; i++) {   //delete each pointer memory
		delete ps[i];
	}

	delete [] ps;								//delete array pointer memory

	system("pause");
	return 0;
}
