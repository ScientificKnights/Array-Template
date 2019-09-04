#include <iostream>
#include "Array.h"
#include "Point.h"
#include "NumericArray.h"
#include "ArrayException.h"

using std::cout;
using std::endl;

//goal: test Numeric Array

int main()
{
	try
	{
		
		NumericArray<int> NumericArray1(3);								//Size 3
		cout << "Array 1: Size " << NumericArray1.Size() << endl;
		for (int i = 0; i < NumericArray1.Size(); i++)						//all value is 1
		{
			NumericArray1[i] = 1;
			cout << NumericArray1[i] << endl;
		}

		NumericArray<int> NumericArray2(5);								//Size 5
		cout << "Array 2: Size " << NumericArray2.Size() << endl;
		for (int i = 0; i < NumericArray2.Size(); i++)						//all value is 2
		{
			NumericArray2[i] = 2;
			cout << NumericArray2[i] << endl;
		}

		NumericArray<int> NumericArray3(NumericArray2);		//Size 5
		cout << "Array 3: Size " << NumericArray3.Size() << endl;
		for (int i = 0; i < NumericArray3.Size(); i++)						//all value is 2
		{
			cout << NumericArray3[i] << endl;
		}

		/*
		cout << "Test two arrays have different size:" << endl;
		NumericArray3= NumericArray2+NumericArray1;			//Size5=Size5+Size3
		*/

		cout << "\nTest sum of array 2 and array 3" << endl;
		NumericArray<int> NumericArray4(5);
		NumericArray4 = NumericArray2 + NumericArray3;
		for (int i = 0; i < NumericArray4.Size(); i++)						//all value is 2
		{
			cout << NumericArray4[i] << endl;
		}

		cout << "\nTest scale of array: array 2 * 2" << endl;
		NumericArray4 = NumericArray2*2;
		for (int i = 0; i < NumericArray4.Size(); i++)						//all value is 2
		{
			cout << NumericArray4[i] << endl;
		}

		cout << "\nTest Dot Product of array 2 and array 3" << endl;
		int result1;
		result1 = NumericArray2.DotProduct(NumericArray3);
		cout << "result=" << result1 << endl;

		//We assume in dot product we multiply the same type <T> together
		//and also assume <T>*<T> is defined. 
		//I can create a numeric array with Point objects after i define <Point>*<Point>
		cout << "\nTest Dot Product of two points" << endl;
		double result2;
		NumericArray<Point> NumericArray5(2);		//point array
		NumericArray<Point> NumericArray6(2);		//point array
		result2 = NumericArray5.DotProduct(NumericArray6); 
		cout << "result=" << result2 << endl;

	}
	catch (ArrayException & ae)						//catch error
	{
		cout << ae.GetMessage() << endl;			//print error message
	}

	system("pause");
	return 0;
}
