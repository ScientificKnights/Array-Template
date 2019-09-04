# Build templated Array step by step
## 1. Dynamically creating objects
The stack is limited in size thus when creating many objects, the stack will overflow. Also arrays created on the stack can only have a fixed size determined at compile time. To overcome these problems we have to create objects on the heap using new.  
```
Point * p1=new Point(1,1); delete p1;
Point * ps=new Point[n]; delete []ps;
```
## 2. Creating array of Pointers
With an array of Points, all points are created with the default constructor.  
When creating an array of pointers, each element in the array must be created separately but can be created with other constructors than the default constructor.  

Thus creating an array of pointers is a two step process:  
  
• Create an array of Point pointers with 3 elements on the heap.  
```Point** ps = new Point*[3];```  
  
• Create for each element in the array a point on the heap.  
```ps[1] = new Point(1, 2);```  
  
• Iterate the array and print each point in the array.  
  
• Iterate the array again and delete each point in the array.  
```delete ps[i];```  
  
• Delete the array itself.  
```delete [] ps;```  
## 3. Array Class for Point Class
• Add a default constructor that allocates for example 10 elements.  
• Add a constructor with a size argument.  
• Add a copy constructor. Keep in mind that just copying the C array pointer will create an Array object that shares the data with the original Array object. Thus you need to allocate a new C array with the same size and copy each element separately.  
• Add a destructor. It should delete the internal C array. Don’t forget the square brackets.  
• Add an assignment operator. Keep in mind you can’t copy only the C array pointers just as in the case of the copy constructor. Also don’t forget to delete the old C array and allocate new memory before copying the elements. This is because C arrays can’t grow.  
• Add the following const version of the square bracket operator. For const Array, if Array[index] return Point &, it means Array can be changed. We need return type const Point & and also function as const since we don't want to change const Array object.  
## 4. Bounds checking
in Class
```
if() throw -1;
```  
in main
```
try{
}
catch (int err){
  if (err==-1){}
}
```  
## 5. Exception Objects
abstract Class ArrayException and derived class OutofBoundsException.  
catch ArrayException in main and print error with derived class funciton.  
## 6. Templated Array Class
In test we can either include the source file or include the h file by including source in the end of h file.  
## Advanced 1. Static variable
static variables are shared between all instances of class. if change static variable in one Array<int>, all Array<int> will change, but Array<double> is not changed.
## Advanced 2. Numeric Array (generic inheritance)
Put extra functions in derived class.  
## Advanced 3. Point Array (concrete inheritance)
Create a derived class of which the template argument is fixed to a specific type(Point).
