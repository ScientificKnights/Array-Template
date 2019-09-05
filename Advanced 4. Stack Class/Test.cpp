#include "Stack.h"
#include <iostream>
using std::cout;
using std::endl;

//Test Stack class Pop and Push function-ex 5
//update: catach out of bound error and rethrow in pop/push

int main()
{
	//Part1: test push and stackfullexception
	Stack<int> stack1(5);		//Array size of Stack is 5
	try	{
		cout << "Test Push:\n";
		for (int i = 0; i < 10; i++) {		//10 is larger than 5
			stack1.Push(i);					//push i into first 5 and error in last five
			cout << "current " << stack1.Current() << endl;
		}
	}
	catch (StackFullException & ae) {
		cout << "Error: stack is full!!!!!!!!!!!!!!\n";
	}
	//Part2: test pop and stackemptyexception
	try	{
		cout << "\nTest Pop:\n";
		for (int i = 0; i < 10; i++) {		//pop out data
			cout << "current " << stack1.Current() << endl;
			cout << "Pop out " << stack1.Pop() << endl;		//pop from 4 to 0 out, then error
		}
	}
	catch (StackEmptyException & ae) {
		cout << "Error: stack is empty!!!!!!!!!!!!!!\n";
	}

	system("pause");
	return 0;
}
