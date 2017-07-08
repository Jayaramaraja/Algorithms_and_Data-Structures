#include <iostream>

using namespace std;
//Binary search using recursive function
int Binary(int A[15],int i,int j,int value)
{
int mid=(i+j)/2;

if (value>A[j])
{
 cout<<"The element is not found in the list"<<endl;
return 20;
}
if (A[mid]==value)                      //base condition.
return mid;
if (A[mid]>value)
return Binary(A,i,mid-1,value);
else
return Binary(A,mid+1,j,value);
}
int main()
{
    int arry[15];                            //array to store the sorted list
    int x,i,value,start=0;

cout<<"****************************************************************************"<<endl;
cout<<"                   ASSIGNMENT 1"<<endl;
cout<<"             Binary sort in the array"<<endl;
cout<<"****************************************************************************"<<endl;
cout<<"These are the elements in the first array"<<endl;
//   The elements in the list are added in multiples of 10
//   eg. 0 10 20 30 40 50 60 70 80 90 100 110 120 130 140- contains 15 elements
//    Similar to hard coding the value in the array.
    for(i=0;i<=14;i++)
    {
         arry[i]=(i*10);
         cout<<arry[i]<<"  ";
    }
    cout<<endl<<"Enter the element to be searched in the given array"<<endl;
    cin>>value;

    x=Binary(arry,start,i,value);
    if(x!=20)
    cout<<"The element is found in the location\t"<<x+1<<endl;
    cout<<"**************************************************"<<endl;

    // The elements are hard coded into the array-16 elements

    int array[]={0,11,22,33,44,55,66,77,88,99,111,122,133,144,155,166};
    cout<<"The second list has the following element"<<endl;
    for(i=0;i<=15;i++)
    {
         cout<<array[i]<<"  ";
    }
    cout<<endl<<"Enter the element to be searched in the given array"<<endl;
    cin>>value;
     x=Binary(array,start,i,value);
     if(x!=20)
    cout<<"The element is found in the location\t"<<x+1<<endl;
    return 0;
}
