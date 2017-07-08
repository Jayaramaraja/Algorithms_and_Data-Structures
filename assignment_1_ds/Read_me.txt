
************************************************************************
                         ASSIGNMENT 1
************************************************************************

Selection Sort using linked list:
--------------------------------
->Compilation Procedure:
1.The code and screen shot for the execution of the code has been uploaded.
2.After compilation, it prompts the user to input any positive number to perform the selection sort.
3.The program exits if non-positive number is given as input.
4.The node are sorted using selection sort.

->Code Structure:
1.The Selection sort uses 2 temporary variables: swap and temp

--------    ----------   --------          ----------
| node 1| - | node 2 | - | node |....... - | node 10|
--------    ----------   --------          ----------
  ^        |<------------------------------------->|
  |               temp var moves and if it finds any smaller element- reinitialize that element as smallest and swaps 
small

2.Swap is done by swapping nodes

--------    ----------          --------     ----------
| node 1| - | node 2 | -....... | node n| - | node n+1|
--------    ----------           --------    ----------
   ^            ^                 ^           ^  
   |            |                 |           | 
prev 1        swap1             prev2       swap2

The node links are changed to swap.


Binary Search in the array:
--------------------------

1.The values are hard coded in the array(for 15 and 16 elements)
2.Binary search is obtained by Recursive function call
3.Checks the mid value for each and reduces the search area. Thus performing faster search of the order of O(log n).
4.Recursively calls the function when until the midpoint becomes the node to be searched or else returns not found. 

Files:
Screen shots:
Selection sort -sort1.jpg,sort2.jpg
Binary sort- binary1.jpg, binary2.jpg

code:
selsortassign.cpp
binary.cpp

 

