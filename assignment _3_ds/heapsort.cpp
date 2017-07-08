#include <iostream>
#include <cstdlib>
using namespace std;
 void heapify(int arry[],int index)     //build heap using perculate up
 {

     int left=index-1;
     int right=index;
     int parent=left/2;
     int largest=parent;
     if(arry[left]>arry[parent]&&arry[left]>arry[right])
     largest=left;
     if(arry[right]>arry[parent]&&arry[right]>arry[left])
     largest=right;

     if (index>16)
     return;
     if(index==1)
     return;

     if(largest!=parent)
     {
         int temp;
         temp=arry[parent];
         arry[parent]=arry[largest];
         arry[largest]=temp;
         int i;
         for(i=right;i<16;i+=2)
         heapify(arry,i);
     }
 }
 void heapsort(int arry[],int index)         //percolate down in the affected tree structure
 {
     int parent;
     int largest;
     parent=index;
     largest=parent;
     int left=parent*2;
     int right=parent*2+1;
     if(arry[left]>arry[parent]&&arry[left]>arry[right]&&(left<arry[0]))
     {
           largest=left;
     }
     if(arry[right]>arry[parent]&&arry[right]>arry[left]&&(right<arry[0]))
     {
           largest=right;
     }
     if(largest!=parent)
     {
         int temp;
         temp=arry[parent];
         arry[parent]=arry[largest];
         arry[largest]=temp;
         heapsort(arry,largest);
     }
 }
int main()
{
int arry[16];  //Array with 15 elements--- index zero stores the length
int i,j;

cout<<"****************************************************************************"<<endl;
cout<<"                   ASSIGNMENT 3"<<endl;
cout<<"                Heap Sort in Array"<<endl;
cout<<"****************************************************************************"<<endl;
//Creating 15 random elements in the array
arry[0]=15;                //initialize the size of the array at index 0.


for(i=1;i<16;i++)
{
    arry[i]=rand()%100+1;
}

cout<<"The given array before heapify"<<endl;
for(i=0;i<16;i++)
{
    cout<<"  "<<arry[i];
}
cout<<endl;

for (i = 15; i > 1; i-=2)
 {

   heapify(arry, i);
    for(j=0;j<16;j++)
    {
        cout<<"  "<<arry[j];
    }
    cout<<endl;

 }


/*for (int i=n-1; i>=0; i--)
    {
       swap(arr[0], arr[i]);
       heapify(arr, i, 0);
    }
    */
    cout<<endl;
for(i=0;i<16;i++)
{
    cout<<"  "<<arry[i];
}
cout<<endl<<"done bilding heap"<<endl;
cout<<endl<<"******heapsort*******"<<endl;
cout<<"Step by step procedure for each swap with perculate down"<<endl;
while(arry[0]>1)             //arry[0] contains the size of the array
{
int swap;
swap=arry[arry[0]];
arry[arry[0]]=arry[1];

arry[1]=swap;
cout<<arry[1]<<" swaps "<<arry[arry[0]]<<endl;
arry[0]--;
heapsort(arry,1);
 for(j=0;j<16;j++)
    {
        cout<<"  "<<arry[j];
    }
    cout<<endl;
 }

cout<<endl<<"Done heap sorting"<<endl;
 for(j=0;j<16;j++)
    {
        cout<<"  "<<arry[j];
    }
cout<<endl;
return 0;
}



