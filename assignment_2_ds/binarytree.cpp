#include <iostream>
#include <cstdlib>
using namespace std;
struct node            //node declaration of BST
{
int data;
node *left;
node *right;
};
class binary_tree
{
 public:
void insertnode(struct node**,struct node*);
void inorder_display(struct node*);
void deletenode(struct node**,int);
};
void binary_tree::inorder_display(struct node *root)
{
if (root==NULL)
return;
inorder_display(root->left);
cout<<root->data<<"  ";
inorder_display(root->right);
}
void binary_tree::insertnode(struct node **root,struct node *newnode)
{
    if((*root)==NULL)
    {
        (*root)=newnode;
        return;
    }
    if((*root)->data<newnode->data)
    {
        if((*root)->right==NULL)
        {
            (*root)->right=newnode;
        }
        else
        insertnode(&(*root)->right,newnode);
    }
   else if((*root)->data>newnode->data)
    {
        if((*root)->left==NULL)
        {
          (*root)->left=newnode;
        }
        else
        insertnode(&(*root)->left,newnode);
    }

}
void binary_tree::deletenode(struct node **root,int element)   //delete node without using parent as reference
{
if((*root)==NULL)
{
cout<<"The element is not found in the bst"<<endl;
return;
}
if((*root)->data==element)                        //enters loop when element is found
{
   int i=0;
    node *temp;
   if((*root)->left==NULL&&(*root)->right==NULL)    //delete leaf node
   {
       cout<<"Deleted the leaf node "<<(*root)->data<<endl;
        delete *root;
       (*root)=NULL;
        return;
   }
   if((*root)->left&&(!(*root)->right))               //delete node with only left child
   {
       node *temp=(*root);
        if((*root)->left->right)
        {
            temp=(*root)->left->right;
            (*root)->right=temp;
            delete (*root)->left->right;
            (*root)->left->right=NULL;
        }
       (*root)->data=(*root)->left->data;
       (*root)=(*root)->left;
        delete temp;
        temp=NULL;
        cout<<"Deleted node with one left child and replaced with "<<(*root)->data<<endl;
        return;
   }
   if((*root)->right&&(!(*root)->left))       //delete node with only right child
   {
        node *temp=(*root);
        if((*root)->right->left)
        {
            temp=(*root)->right->left;
            (*root)->left=temp;
             delete (*root)->right->left;
            (*root)->left->right=NULL;
        }
       (*root)->data=(*root)->right->data;
        (*root)=(*root)->right;
         delete temp;
         temp=NULL;
         cout<<"Deleted node with one right child and replaced with  "<<(*root)->data<<endl;
         return;
   }
if((*root)->left&&(*root)->right)          //delete node with 2 child
{                                          //Use successor to replace the deleted node
if((*root)->right->left==NULL)
{
    node *temp=(*root)->right;
    temp->left=(*root)->left;
    (*root)=temp;
    cout<<"Deleted node and replaced with successor  "<<(*root)->data<<endl;
    return;
}
node *prev=(*root)->right;
node *temp=(*root)->right->left;
while(temp->left!=NULL)          //to find the successor of the node to be deleted
{
 prev=prev->left;
 temp=temp->left;
}
prev->left=temp->right;
temp->right=(*root)->right;
temp->left=(*root)->left;
(*root)=temp;
cout<<"Deleted node and replaced with successor  "<<(*root)->data<<endl;
delete temp;
temp=NULL;
return;
}
}
if((*root)->data<element)
deletenode(&(*root)->right,element);     //recursive call untill it finds the node to be deleted
else
deletenode(&(*root)->left,element);
}


int main()
{
    struct node *root=new node;
    int choice=1,n;
    binary_tree bst;
    root->data=3;     //root node inserted
    root->left=NULL;
    root->right=NULL;
cout<<"****************************************************************************"<<endl;
cout<<"                   ASSIGNMENT 2"<<endl;
cout<<"           Binary tree in the linked list"<<endl;
cout<<"****************************************************************************"<<endl;
	while(choice==1||choice==2||choice==3||choice==4)
	{
	cout<<endl<<"Choose the number to select the particular operation:"<<endl<<"1.Insert node 14 nodes to form a random tree"<<endl<<"2.Inorder Display"<<endl<<"3.Delete node"<<endl<<"4.Add node"<<endl;

	cin>>choice;
	switch(choice)
	{
	case 1:
	cout<<"The 14 nodes inserted are:"<<endl;
	for(int i=0;i<=14;i++)                //inserts 14 random nodes- 15 including root node.
		{
	node* newnode=new node;
	n=rand()%100+1;
	cout<<n<<endl;
	newnode->data=n;
	newnode->left=NULL;
	newnode->right=NULL;
	bst.insertnode(&root,newnode);
	}
    break;
    case 2:
   bst.inorder_display(root);
    break;
    case 3:
    {
        int element;
        cout<<"enter the element to be deleted from the tree:"<<endl;
        cin>>element;
      bst.deletenode(&root,element);
    }

     break;
     case 4:                              //manual insert node
     {
    node* newnode=new node;
	cout<<"Enter the element to be inserted in the tree"<<endl;
	cin>>n;
	newnode->data=n;
	newnode->left=NULL;
	newnode->right=NULL;
	bst.insertnode(&root,newnode);
    break;
     }

   default:
   cout<<"Enter a valid selection";
   break;

}
}
    return 0;
}
