#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<queue>
#include<limits>
// vertices 10 edge 15
//using adjacency matrix
#define vertices 10

//declaring inbuilt queue
using namespace std;
queue< int >q;

//print graph- prints the edges of the graph
void print_graph_undirected(int incident_matrix[vertices][vertices])
{
    int i,j;
    for(i=0;i<vertices;i++)
    {
        for(j=0;j<i;j++)
        {
            if(incident_matrix[i][j]>0)
                printf("edge %d%d with weight %d \n",i,j,incident_matrix[i][j]);
        }
    }
}

//prim's algorithm-minimum spanning tree
//visited_matrix keeps track of the nodes visited in the graph
void prim(int adj_matrix[vertices][vertices],int visited_matrix[vertices],int start_node)
{
    q.push(start_node);
    //defining min to the max element in the type <int>

    int min=std::numeric_limits<int>::max();
    int cur,col,i,j,node1,node2,count=1;
    while(!q.empty())
    {
        if(count==vertices)
        break;
        min=std::numeric_limits<int>::max();
        cur = q.front();
        q.pop();
        visited_matrix[cur]=-1;
        for(i=0;i<vertices;i++)
        {
            for(j=0;j<vertices;j++)
            {
                if(adj_matrix[i][j])
                {
                    if(visited_matrix[i]==-1&&visited_matrix[j]==0)
                    {
                        if(min>adj_matrix[i][j])
                        {
                            min=adj_matrix[i][j];
                            node1=i;
                            node2=j;
                        }
                    }
                }
            }
        }
        cout<<"node "<<node1<<node2<<" with weight "<<adj_matrix[node1][node2]<<"\n";
        if(visited_matrix[node2]==0)
        {
         q.push(node2);
         count++;
        }
    }
}
int main()
{
    int i,j,k,start_node=0;//start node for the graph can be changed
    int visited_matrix[vertices]={0};
    //undirected connected matrix
    int adj_matrix[vertices][vertices] =
    {
{0, 1, 3, 0, 0, 0, 0, 0, 0, 0},
{1, 0, 0, 8, 9, 0, 0, 0, 0, 0},
{3, 0, 0, 7, 0, 5, 0, 0, 0, 0},
{0, 8, 7, 0, 0, 6, 2, 0, 0, 0},
{0, 9, 0, 0, 0, 0, 11, 10, 0, 0},
{0, 0, 5, 6, 0, 0, 0, 0, 5, 0},
{0, 0, 0, 2, 11, 0, 0, 3, 15, 0},
{0, 0, 0, 0, 10, 0, 3, 0, 0, 4},
{0, 0, 0, 0, 0, 5, 15, 0, 0, 1},
{0, 0, 0, 0, 0, 0, 0, 4, 1, 0}
     };
cout<<"The graph has the following edges:"<<endl;
cout<<"****************************************************************"<<endl;
print_graph_undirected(adj_matrix);
cout<<"****************************************************************"<<endl;
cout<<"                        PRIM'S MST"<<endl;
cout<<"****************************************************************"<<endl;
prim(adj_matrix,visited_matrix,start_node);
return 0;
}
