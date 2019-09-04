#include "Array.h"
#include "Point.h"

//Array class: handle memory of array of Point class
//get array size
//set and get array element

Array::Array()					//default constructor that allocates for 10 elements
{
	m_data = new Point[5];
	m_size = 5;
}

Array::Array(unsigned int size)		//constructor with a size argument
{
	m_data = new Point[size];
	m_size = size;
}

Array::Array(const Array & ay)		//copy constructor
{
	m_size = ay.m_size;						//copy size
	m_data = new Point[m_size];
	for (int i = 0; i < m_size; i++)		//copy each point
		m_data[i] = ay.m_data[i];		//both will run
										//*(m_data + i) = *(ay.m_data + i);
}

Array::~Array()				//destructor
{
	delete[] m_data;
}

Array& Array::operator=(const Array & source)		//define assignment
{
	if (this == &source)
		return *this;
	delete[] m_data;							//delete old memory
	m_size = source.m_size;				//copy size
	m_data = new Point[m_size];
	for (int i = 0; i < m_size; i++)		//copy each Points
		m_data[i] = source.m_data[i];
	return *this;
}

unsigned int Array::Size() const			//returns the size of the array
{
	return m_size;
}

void Array::SetElement(unsigned int index, const Point & newpoint)			//sets an element
{
	if (index >= m_size) throw - 1;		//Outside bounds
	m_data[index] = newpoint;				//Ok now
}

Point Array::GetElement(unsigned int index) const		//return the element by reference
{
	if (index >= m_size) throw - 1;		//Outside bounds
	return m_data[index];						//Ok now
}

Point & Array::operator[](unsigned int index)						//square bracket operator
{
	if (index >= m_size) throw - 1;		//Outside bounds
	return m_data[index];						//Ok now
}

const Point & Array::operator[](unsigned int index) const		//const version square bracket operator
{
	if (index >= m_size) throw - 1;		//Outside bounds
	return m_data[index];						//Ok now
}
