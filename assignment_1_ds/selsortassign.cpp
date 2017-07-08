#include <iostream>
#include <cstdlib>
using namespace std;
//Declaration for the node
struct node
{
int ele;              //Represents the data
node *next;           //Represents the pointer
};
class assign1
{

public:
struct node *head=new node;
 void firstele(struct node *head,int n)
{
head->ele=n;
head->next=NULL;
}
void display(struct node *head)
{
cout<<"The elements are:"<<endl;
node *cur=head;
while(cur!=NULL)
{
cout<<cur->ele<<"  ";
cur=cur->next;
}
}
void addnode(struct node *head,int n)
{
node *newnode=new node;
newnode->ele=n;
newnode->next=NULL;

node *current=head;
while(current)
{
if (current->next==NULL)
{
current->next=newnode;

return;
}
current=current->next;
}
}
void selsort(struct node **head)
{
    node *small,*temp=*head;
    node *current=*head;
    while(current->next!=NULL)
    {
        small=current;
        temp=current->next;
        while(temp)
        {
            if (temp->ele<small->ele)
            {
               small=temp;
            }
            temp=temp->next;
        }
      swap(head,current->ele,small->ele);
    current=small;
    current=current->next;
     }
}

//Swap function to swap the two nodes

    void swap(struct node **head, int i,int j)
    {
        node *swap1=*head;
        node *swap2=*head;
        node *prev1=NULL,*prev2=NULL,*temp;

        while(swap1->ele!=i)
        {
           prev1=swap1;
           swap1=swap1->next;
        }
         while(swap2->ele!=j)
        {
           prev2=swap2;
           swap2=swap2->next;
        }
        if (prev1==NULL)
        {
            *head=swap2;
        }
        else
        {
           prev1->next=swap2;

        }
        if(prev2==NULL)
        {
           *head=swap1;
        }
        else
        {
            prev2->next=swap1;

        }
        temp=swap1->next;
        swap1->next=swap2->next;
        swap2->next=temp;
    }

};
int main()
{
assign1 a;                         //Creating the object for the class assign1
int i,choice=0;
struct node *headnode;
headnode=a.head;
cout<<"****************************************************************************"<<endl;
cout<<"                   ASSIGNMENT 1"<<endl;
cout<<"           Selection Sort using linked list"<<endl;
cout<<"****************************************************************************"<<endl;
//Creating 10 random elements in the linked list
a.firstele(headnode,rand()%100+1);
for(i=0;i<10;i++)
{

    a.addnode(headnode,rand()%100+1);
}
a.display(headnode);
cout<<endl<<"Enter any positive number to perform the selection sort for the above list."<<endl;
cin>>choice;
if(choice)
{
 a.selsort(&headnode);
a.display(headnode);
cout<<endl<<"The given list has been sorted."<<endl;

}
else
{
cout<<"You have not entered the positive number.The code will exit."<<endl;
}
return 0;
}



