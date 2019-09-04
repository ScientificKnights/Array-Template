# Build Array step by step
## Dynamically creating objects
The stack is limited in size thus when creating many objects, the stack will overflow. Also arrays created on the stack can only have a fixed size determined at compile time. To overcome these problems we have to create objects on the heap using new.  
```
Point * p1=new Point(1,1); delete p1;
Point * ps=new Point[n]; delete []ps;
```
