#include <iostream>
#include "Array.h"
#include "Point.h"
#include "PointArray.h"
#include "ArrayException.h"

using std::cout;
using std::endl;

//goal: test PointArray class and length function

int main(){
	try	{
		PointArray PointArray1(6);								//new point array
		cout << "Array 1: Size " << PointArray1.Size() << endl;
		for (int i = 0; i < PointArray1.Size(); i++) {						//assign values for every point and print out
			PointArray1[i] = Point(0,i);
			cout << PointArray1[i] << endl;
		}

		cout << "\nThe length of array of Points are ";
		cout << PointArray1.Length() << endl;						//calculate array length
	}
	catch (ArrayException & ae) {						//catch error
		cout << ae.GetMessage() << endl;			//print error message
	}

	system("pause");
	return 0;
}
