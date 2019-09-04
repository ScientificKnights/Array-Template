#include <iostream>
#include "Array.h"
#include "ArrayException.h"

using namespace std;
//goal: test Template Array class has static members

int main()
{
	try									//test out of range block
	{
		Array<int> intArray1;				//Array<int>
		Array<int> intArray2;
		Array<double> doubleArray;

		cout << intArray1.DefaultSize() << endl;
		cout << intArray2.DefaultSize() << endl;
		cout << doubleArray.DefaultSize() << endl;
		//print 5 5 5
		//2 Array<int> and Array<double> objects all have default size 5.

		intArray1.DefaultSize(15);
		cout << intArray1.DefaultSize() << endl;
		cout << intArray2.DefaultSize() << endl;
		cout << doubleArray.DefaultSize() << endl;
		//print 15 15 5
		//2 Array<int> change default size to 15
		//and Array<double> still have default size 5.

		//conclustion: Array<T> share static member with all Array<T> objects
		//but they don't share with other kinds objects like Array<U>
	}
	catch (ArrayException & ae)						//catch error
	{
		cout << ae.GetMessage() << endl;			//print error message
	}

	system("pause");
	return 0;
}
