#include <iostream>
#include "Point.h"
#include "Array.h"
#include "ArrayException.h"

using namespace std;
//goal: test Array class using template method

int main() {
	try {
		//test constructor with a size argument
		cout << "test constructor with a size argument:" << endl;
		Array<Point> array1(4);	//constructor with a size argument
		cout << "Array 1 size: " << array1.Size() << endl;
		for (int i = 0; i < array1.Size(); i++)				//print array1
			cout << i + 1 << ": " << array1[i] << endl;

		//test set and get with []
		cout << "test set and get with []" << endl;
		cout << "Array 1 size: " << array1.Size() << endl;
		for (int i = 0; i < array1.Size(); i++)				//set value and print
		{
			array1[i] = Point(i, i);		//set Points
			cout << "Point " << i + 1 << ": " << array1[i] << endl;		//get Points
		}
	}
	catch (ArrayException & ae)						//catch error
	{
		cout << ae.GetMessage() << endl;			//print error message
	}

	system("pause");
	return 0;
}
