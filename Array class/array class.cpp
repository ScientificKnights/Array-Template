#include <iostream>
#include "Point.h"
#include "Array.h"

using namespace std;
//goal: test Array class

int main() {

	//test default constructor
	cout << "test default constructor:" << endl;
	Array array1;			//default constructor
	cout << "Array 1 size: " << array1.Size() << endl;
	for (int i = 0; i < array1.Size(); i++)
		cout << i+1 << ": "<<array1[i] << endl;

	//test constructor with a size argument
	cout << "test constructor with a size argument:" << endl;
	Array array2(4);	//constructor with a size argument
	cout << "Array 2 size: " << array2.Size() << endl;
	for (int i = 0; i < array2.Size(); i++)
		cout << i+1 << ": " << array2[i] << endl;

	//array2[2] = Point(2, 2);

	//copy constructor
	cout << "test copy constructor,copy Array 2 to Array 3" << endl;
	Array array3(array2);	//copy constructor
	cout << "Array 3 size: " << array3.Size() << endl;
	for (int i = 0; i < array3.Size(); i++)
		cout << i + 1 << ": " << array3[i] << endl;

	//assign operator
	cout << "assign Array 1 to Array 3" << endl;
	array3=array1;	//assign operator
	cout << "Array 3 size: " << array3.Size() << endl;		//print after assign
	for (int i = 0; i < array3.Size(); i++)
		cout << i + 1 << ": " << array3[i] << endl;

	//test SetElement and GetElement
	cout << "test SetElement and GetElement" << endl;
	cout << "Array 3 size: " << array3.Size() << endl;
	for (int i = 0; i < array3.Size(); i++)	{
		array3.SetElement(i, Point(i, i));		//set Points
		cout << "Point " << i + 1 << ": " << array3.GetElement(i) << endl;		//get Points
	}

	//test set and get with []
	cout << "test set and get with []" << endl;
	cout << "Array 2 size: " << array2.Size() << endl;
	for (int i = 0; i < array2.Size(); i++) {
		array2[i] = Point(i, i);		//set Points
		cout << "Point " << i + 1 << ": " << array2[i] << endl;		//get Points
	}

	system("pause");
	return 0;
}
