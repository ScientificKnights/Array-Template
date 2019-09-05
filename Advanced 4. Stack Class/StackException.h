#ifndef STACKEXCEPTION_H
#define STACKEXCEPTION_H


//define the StackException base and derived class 
//which handles exception happens in Stack class

class StackException
{
public:
	StackException() {};
	virtual ~StackException() {}
};

class StackFullException :public StackException			//derived full class from StackException
{
public:
	StackFullException() {}
	virtual ~StackFullException() {}
};

class StackEmptyException :public StackException		//derived empty class from StackException
{
public:
	StackEmptyException() {}
	virtual ~StackEmptyException() {}
};

#endif
