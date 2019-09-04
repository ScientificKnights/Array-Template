#include <iostream>
#include "Point.h"
#include "Array.h"

using namespace std;

//goal: test Bounds checking of Array class
int main()
{
	// constructor with a size argument
	cout << "Constructor with a size argument:" << endl;
	Array array1(4);	//constructor with a size argument
	cout << "Array 1 size: " << array1.Size() << endl;		//print array size

	//cout << array1[4];						//print a point out of bound
	//The program will break if no try...catch block

	//test index operator out of bound
	cout << "test index operator out of bound" << endl;
	try
	{
		for (int i = 0; i < array1.Size()+2; i++)			//print TWO numbers out of bound
			cout << i + 1 << ": " << array1[i] << endl;
		//Only prints one out of bound message. it means throw can break the for block.
	}
	catch (int err)
	{
		if (err = -1)
			cout << "Your input is out of bound" << endl;
	}

	//test SetElement and GetElement out of bound
	cout << endl <<"test SetElement and GetElement out of bound" << endl;
	try
	{
		for (int i = 0; i < array1.Size()+2; i++)
		{
			array1.SetElement(i, Point(i, i));		//set Points
			cout << "Point " << i + 1 << ": " << array1.GetElement(i) << endl;		//get Points
		}
		//Only prints one out of bound message. it means throw can break the for block.
	}
	catch (int err)
	{
		if (err = -1)
			cout << "Your input is out of bound" << endl;
	}

	system("pause");
	return 0;
}
