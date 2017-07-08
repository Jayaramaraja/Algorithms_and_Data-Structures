#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<queue>
#include<stack>
// vertices 11 edge 15
#define row 11
#define column 15
//Creating queue and stack
using namespace std;
stack< int >s;
queue< int >q;


void dfs_directed(int incident_matrix[row][column],int visited_matrix[row],int start_node1)
 {
    s.push(start_node1);
    visited_matrix[start_node1]=1;
    int cur;
    while(!s.empty())
    {
        cur = s.top();
        s.pop();
        cout<<"Visiting node   "<<cur<<"\n";
        visited_matrix[cur]=-1;
        for(int i=0;i<column;i++)
         {
            if(incident_matrix[cur][i]==1)
             {
                for(int j=0;j<row;j++)
                 {
                    if(incident_matrix[j][i]==-1 && visited_matrix[j]==0)
                    {
                        s.push(j);
                        visited_matrix[j]=1;
                    }
                }
            }
        }
    }
    for(int a=0;a<row;a++)
        if(visited_matrix[a]==0)
        {
            cout<<"     ***new forrest***"<<endl;
            dfs_directed(incident_matrix,visited_matrix,a);
        }
}


void dfs_undirected(int incident_matrix[row][column],int visited_matrix[row],int start_node1)
{
    s.push(start_node1);
    visited_matrix[start_node1]=1;
    int cur;
    while(!s.empty())
     {
        cur = s.top();
        s.pop();
        cout<<"Visiting node   "<<cur<<"\n";
        visited_matrix[cur]=-1;
        for(int i=0;i<column;i++)
        {
            if(incident_matrix[cur][i]==1 || incident_matrix[cur][i]==-1)
             {
                for(int j=0;j<row;j++)
                 {
                    if((incident_matrix[j][i]==-1 || incident_matrix[j][i]==1) && visited_matrix[j]==0)
                     {
                        s.push(j);
                        visited_matrix[j]=1;
                    }
                }
            }
        }
    }
    for(int a=0;a<row;a++)
        if(visited_matrix[a]==0)
        {
            cout<<"     ***new forest***"<<endl;
            dfs_undirected(incident_matrix,visited_matrix,a);
        }
}


void bfs_directed(int incident_matrix[row][column],int visited_matrix[row],int start_node1)
 {
    q.push(start_node1);
    visited_matrix[start_node1]=1;
    int cur;
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        cout<<"Visiting node   "<<cur<<"\n";
        visited_matrix[cur]=-1;
        for(int i=0;i<column;i++)
         {
            if(incident_matrix[cur][i]==1)
            {
                for(int j=0;j<row;j++)
                 {
                    if(incident_matrix[j][i]==-1 && visited_matrix[j]==0)
                    {
                        q.push(j);
                        visited_matrix[j]=1;
                    }
                }
            }
        }
    }
    for(int a=0;a<row;a++)
        if(visited_matrix[a]==0)
        {
            cout<<"     ***new forrest***"<<endl;
            bfs_directed(incident_matrix,visited_matrix,a);
        }
}

void bfs_undirected(int incident_matrix[row][column],int visited_matrix[row],int start_node1)
{
    q.push(start_node1);
    visited_matrix[start_node1]=1;
    int cur;
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        cout<<"Visiting node   "<<cur<<"\n";
        visited_matrix[cur]=-1;
        for(int i=0;i<column;i++)
        {
            if(incident_matrix[cur][i]==1 || incident_matrix[cur][i]==-1)
             {
                for(int j=0;j<row;j++)
                {
                    if((incident_matrix[j][i]==-1 || incident_matrix[j][i]==1) && visited_matrix[j]==0)
                    {
                        q.push(j);
                        visited_matrix[j]=1;
                    }
                }
            }
        }
    }
    for(int a=0;a<row;a++)
        if(visited_matrix[a]==0)
        {
            cout<<"     ***new forrest***"<<endl;
            bfs_undirected(incident_matrix,visited_matrix,a);
        }
}

int main()
{
    int i,j,k,start_node=0,edge=0,start_node1=0,edge1=0;
    int visited_matrix[row]={0};
    int visited_matrix1[row]={0};

    //undirected connected matrix
    int incident_matrix[row][column] =
    {
{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0},
{0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        };

//undirected unconnected
    int incident_matrix1[row][column] =
    {
{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
{0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
{0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
    };


// directed disconnected
    int incident_matrix2[row][column] =
    {
{0, -1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{-1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 1, 1, -1, 0, 0, 0, 0, 0, 0, 0, 1},
{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 1, 1, 0, -1},
{0, 0, 0, 0, -1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, -1, -1, 0},
{0, 0, 0, 0, 0, -1, 0, -1, -1, 1, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 1, 0},
{0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        };

//directed connected
    int incident_matrix3[row][column] =
    {
{0, -1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{-1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{0, 0, 0, 0, 1, 1, -1, 0, 0, 0, 0, 0, 0, 0, -1},
{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 1, 1, 0, 0},
{0, 0, 0, 0, -1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, -1, -1, 0},
{0, 0, 0, 0, 0, -1, 0, -1, -1, 1, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 1, 0},
{0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
int choice=1;
cout<<"****************************************************************"<<endl;
cout<<"                        GRAPH- BFS & DFS"<<endl;
cout<<"****************************************************************"<<endl;
    while(choice==1||choice==2||choice==3||choice==4||choice==5||choice==6||choice==7||choice==8)
    {
    cout<<"Enter the choice to display the traversal"<<endl;
    cout<<"BFS-traversal"<<endl<<"-------------"<<endl<<"1.undirected disconnected graph"<<endl<<"2.undirected connected"<<endl<<"3.directed disconnected"<<endl<<"4.directed connected"<<endl;
    cout<<"DFS-traversal"<<endl<<"-------------"<<endl<<"5.undirected disconnected graph"<<endl<<"6.undirected connected"<<endl<<"7.directed disconnected"<<endl<<"8.directed connected"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
        //unconnected
        bfs_undirected(incident_matrix1,visited_matrix,start_node1);
        cout<<"***********************************************************************"<<endl;
        for(int i=0;i<row;i++)
        {
            visited_matrix[i]=0;
        }
        break;
    }
    case 2:
    {
        bfs_undirected(incident_matrix,visited_matrix,start_node);
        cout<<"***********************************************************************"<<endl;
        for(int i=0;i<row;i++)
        {
            visited_matrix[i]=0;
        }
        break;
    }
    case 3:
    {
        //unconnected
        bfs_directed(incident_matrix2,visited_matrix,start_node);
        cout<<"***********************************************************************"<<endl;
        for(int i=0;i<row;i++)
        {
            visited_matrix[i]=0;
        }
        break;
    }
    case 4:
    {
        bfs_directed(incident_matrix3,visited_matrix,start_node);
        cout<<"***********************************************************************"<<endl;
        for(int i=0;i<row;i++)
        {
            visited_matrix[i]=0;
        }
        break;
    }
    case 5:
    {
        //unconnected
        dfs_undirected(incident_matrix1,visited_matrix,start_node1);
        cout<<"***********************************************************************"<<endl;
        for(int i=0;i<row;i++)
        {
            visited_matrix[i]=0;
        }
        break;
    }
    case 6:
    {
        //connected
        dfs_undirected(incident_matrix,visited_matrix,start_node);
        cout<<"***********************************************************************"<<endl;
        for(int i=0;i<row;i++)
        {
        visited_matrix[i]=0;
        }
        break;
    }
    case 7:
    {
        //unconnected
        dfs_directed(incident_matrix2,visited_matrix,start_node);
        cout<<"***********************************************************************"<<endl;
        for(int i=0;i<row;i++)
        {
            visited_matrix[i]=0;
        }
        break;
    }
    case 8:
    {
        //connected
        dfs_directed(incident_matrix3,visited_matrix,start_node);
        cout<<"***********************************************************************"<<endl;
        for(int i=0;i<row;i++)
        {
            visited_matrix[i]=0;
        }
        break;
    }
    default:
    {
        cout<<"Not a valid Selection"<<endl;
        break;
    }
}
}
return 0;

}
