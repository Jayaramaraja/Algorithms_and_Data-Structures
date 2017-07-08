#include <iostream>
#include <cstdlib>
using namespace std;
//Bubble sort in the array

int main()
{
    int arry[15];                           //array to store the data
    int i,j,k,swap=1,temp=0;                //swap is used as a flag to indicate swapping event

cout<<"****************************************************************************"<<endl;
cout<<"                   ASSIGNMENT 2"<<endl;
cout<<"             Bubble sort in the array"<<endl;
cout<<"****************************************************************************"<<endl;
cout<<"These are the elements in the array before the sort"<<endl;
//   The elements in the array are added using the random function
    for(i=0;i<=14;i++)
    {
         arry[i]=rand()%100+1;
    }


    for(i=0;i<=14;i++)
    cout<<arry[i]<<"  ";

    for(i=0;i<14;i++)                       //number of pass- 14 in worst case ie.n-1
    {
        if(!swap)                           //exits the loop when swap doesnt occur
        break;
        for(j=0;j<14-i;j++)                 //each comparsion traversal
        {
            swap=0;
           if(arry[j]>arry[j+1])
        {   swap=1;                         //sets the swap flag
            temp=arry[j];
            arry[j]=arry[j+1];
            arry[j+1]=temp;
        }
        }
        cout<<"\nThe array after "<<i+1<<"th pass\n";
        for(k=0;k<=14;k++)
        cout<<arry[k]<<"  ";
    }
    cout<<"\nThe elements in the array after the bubble sort\n";
    for(i=0;i<=14;i++)
    cout<<arry[i]<<"  ";
    return 0;
}
