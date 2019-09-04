# Build Array step by step
## Dynamically creating objects
The stack is limited in size thus when creating many objects, the stack will overflow. Also arrays created on the stack can only have a fixed size determined at compile time. To overcome these problems we have to create objects on the heap using new.  
```
Point * p1=new Point(1,1); delete p1;
Point * ps=new Point[n]; delete []ps;
```
## Creating array of Pointers
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
## Array Class for Point Class
• Add a default constructor that allocates for example 10 elements.  
• Add a constructor with a size argument.
• Add a copy constructor. Keep in mind that just copying the C array pointer will create an Array object that shares the data with the original Array object. Thus you need to allocate a new C array with the same size and copy each element separately.
• Add a destructor. It should delete the internal C array. Don’t forget the square brackets.
• Add an assignment operator. Keep in mind you can’t copy only the C array pointers just as in the case of the copy constructor.
• Also don’t forget to delete the old C array and allocate new memory before copying the elements. This is because C arrays can’t grow.
