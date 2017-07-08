#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
const int MAX = 20;

void radix_sort(long int *a, int arraySize)
{
	int i, bucket[MAX], maxVal = 0, digitPosition =1 ;
	for(i = 0; i < arraySize; i++)    //finds the maximum value in the array
	{
		if(a[i] > maxVal)
            maxVal = a[i];
	}
	int pass = 1;
	while(maxVal/digitPosition > 0)   //loops according to the maximum value
	{
		int digitCount[10] = {0};     //rests the array
		for(i = 0; i < arraySize; i++)
			digitCount[a[i]/digitPosition%10]++;
		for(i = 1; i < 10; i++)
			digitCount[i] += digitCount[i-1];
		for(i = arraySize - 1; i >= 0; i--)
			bucket[--digitCount[a[i]/digitPosition%10]] = a[i];
		for(i = 0; i < arraySize; i++)   //copy back to the array
			a[i] = bucket[i];
		cout << "pass #" << pass++ << ": ";  //prints after each pass
		for(int b=0;b<20;b++)
        cout<<a[b]<<" ";
        cout<<endl;
		digitPosition *= 10;
	}
 }

int main()
{

	long int sort_element[20]={321546,565,84461,1846,8954,3264,34984,22,68483,56,3,51686,44655,654683,684788,999999,456452,95,4545,945};
	/* In order to get random variables uncomment the lines below and remove the hard coded value from above*/
	/*
	srand(time(NULL));
	for(int i=0;i<20;i++)
	sort_element[i]=rand()%999999+1;
    */
	const size_t element_size = sizeof(sort_element)/sizeof(sort_element[0]);
	cout<<"***************************************************************"<<endl;
	cout<<"                     RADIX SORT"<<endl;
	cout<<"***************************************************************"<<endl;

	cout << "Elements before sorting:"<<endl;
	for(int i=0;i<20;i++)
	cout<<sort_element[i]<<" ";
	cout<<endl<<endl;

	radix_sort(&sort_element[0],element_size);
	cout <<endl<< "Elements after sorting:"<<endl;
	for(int i=0;i<20;i++)
	cout<<sort_element[i]<<" ";
	cout<<endl;
	return 0;
}
