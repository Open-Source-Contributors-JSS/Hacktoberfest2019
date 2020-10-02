#define INFINITY 999
#define MAX 20
#include<iostream>
using namespace std;
class prims
{
	int G[MAX][MAX];
	int n;
	public:
	prims()
	{n=0;}


	void readgraph()
	{
		int i,j,vi,vj,no_of_edges,weight;
		cout<<"Enter no of vertice"<<endl;
		cin>>n;
		cout<<"Enter no of edges";
		cin>>no_of_edges;
		for(int i=0;i<n;i++)
		 for(j=0;j<n;j++)
		   G[i][j]=0;
		cout<<"Enter list of edges"<<endl;
		for(int i=0;i<no_of_edges;i++)
                {
			cout<<"enter an edge(u,v,weight)";

			cin>>vi>>vj>>weight;
			G[vi][vj]=G[vj][vi]=weight;

		}
	}			
			
	void printgraph()
	{
		int i,j;
		cout<<"lis of edges in spanning tree"<<endl;
		for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		 if(G[i][j]!=0)
 			cout<<"(u,v,weight)="<<i<<" ,"<<j<<","<<G[i][j]<<endl;
	}

        int prim(prims &spanning)
{

	int cost[MAX][MAX];
	int u,v,min_dist,dist[MAX],from[MAX];
	int visited[MAX],no_of_edges,min_cost,i,j;
	for(int i=0;i<n;i++)
	for(j=0;j<n;j++)
 	{
	if(G[i][j]==0)
	cost[i][j]=INFINITY;
	else
	cost[i][j]=G[i][j];
	spanning.G[i][j]=0;
	}

	dist[0]=0;visited[0]=1;
	for(i=1;i<n;i++)
	{
	 dist[i]=cost[0][i];
	from[i]=0;
	visited[i]=0;
	}
	min_cost=0;
	no_of_edges=n-1;
	while(no_of_edges>0)
	{
	min_dist=INFINITY;
	for(i=1;i<n;i++)
	if(visited[i]==0&&dist[i]<min_dist )
	{
	v=i;
	min_dist=dist[i];

	}
	u=from[v];
	spanning.G[u][v]=spanning.G[v][u]=dist[v];
	no_of_edges--;
	visited[v]=1;
	for(i=1;i<n;i++)
	if(visited[i]==0&&cost[i][v]<dist[i])
	{
	dist[i]=cost[i][v];
	from[i]=v;

	}
	min_cost=min_cost+cost[u][v];

	}
	spanning.n=n;
	return(min_cost);
	}
};


int main()
{
     prims p1,spanning;
     p1.readgraph();
     int totalcost=p1.prim(spanning);
     cout<<"spanning tree matrix"<<endl;
     spanning.printgraph();
     cout<<"total cost of spanning tree is "<<totalcost;
     return 0;
}


/*OUTPUT:



[@localhost ~]$ g++ prims.cpp
[@localhost ~]$ ./a.out
Enter no of vertice
4
Enter no of edges5
Enter list of edges
enter an edge(u,v,weight)0
1
3
enter an edge(u,v,weight)1
2
5
enter an edge(u,v,weight)2
3
2
enter an edge(u,v,weight)3
0
5
enter an edge(u,v,weight)0
2
4
spanning tree matrix
lis of edges in spanning tree
(u,v,weight)=0 ,1,3
(u,v,weight)=0 ,2,4
(u,v,weight)=2 ,3,2
total cost of spanning tree is 9[bvcoew@localhost ~]$ 
*/


