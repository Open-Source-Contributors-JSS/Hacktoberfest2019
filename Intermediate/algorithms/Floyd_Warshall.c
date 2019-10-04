#include <stdio.h>
#include <stdlib.h>
#define INF 9999	

void displayShortestDistance(int V, int dist[V][V])
{
	int i,j;
	for(i = 0; i < V; i++)
	{
		for(j = 0; j < V; j++)
		{
			if(dist[i][j] == INF)
				printf("%s\t","INF");
			else
				printf("%d\t", dist[i][j]);
		}
		puts("");
	}
}

void floydWarshall(int V,int graph[][V])
{
	int dist[V][V];
	int i,j,k;
	for(i = 0; i < V; i++)
		for(j = 0; j < V; j++)
			dist[i][j] = graph[i][j];

	for(k = 0; k < V; k++)
	{
		for(i = 0; i < V; i++)
		{
			for(j = 0; j < V; j++)
			{
				if(dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	puts("The matrix showing the shortest distance between each vertex is: ");
	displayShortestDistance(V, dist);
}


int main()
{
	/* Let us run the algorithm for the following graph
            10 
       (0)------->(3) 
        |         /|\ 
      5 |          | 
        |          | 1 
       \|/         | 
       (1)------->(2) 
            3           */
	int V = 4;
	int graph[V][V], i, j;
	for(i = 0; i < V; i++)
		for(j = 0; j < V; j++)
		{
			if(i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = INF;
		}
		
    
  	graph[0][1] = 5;
  	graph[0][3] = 10;
  	graph[1][2] = 3;
  	graph[2][3] = 1;

  	puts("The initial weight matrix is: ");
  	displayShortestDistance(V, graph);

    floydWarshall(V,graph); 
	return 0;
}