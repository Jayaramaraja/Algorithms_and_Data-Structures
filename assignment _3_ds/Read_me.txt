
************************************************************************
                         ASSIGNMENT 3
************************************************************************


Heap Sort:
---------------------------------------------------------------
The heapsort algorithm can be divided into two parts.
In the first step, a heap is built out of the data.
The complete binary tree maps the binary tree structure into the array indices; each array index represents a node;array zero index is used to denote the size

  
  iLeftChild(i)  = 2*i + 1
  iRightChild(i) = 2*i + 2

In the second step, a sorted array is created by repeatedly removing the largest element from the heap (the root of the heap), 
and inserting it into the array. The heap is updated after each removal to maintain the heap. Once all objects have been removed from the heap, the result is a sorted array.


The code is implemented by step by step procedure as taught in the class. 


Files:
Screen shots:
heap sort 
            - heapsort1.jpg
	      heapsort2.jpg
	      Diagram1.jpg
	     
code:
heapsort.cpp

 

