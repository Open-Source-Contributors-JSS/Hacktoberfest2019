#include<iostream>
#include<list>
#include<stack>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
    void utilTopologicalSort(int v,bool visited[], stack<int> &Stack); 
public:
    Graph(int V);
    void addEdge(int u, int v);
    void topologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
}
void Graph::utilTopologicalSort(int v,bool visited[], stack<int> &Stack)
{
    visited[v]=true;
    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++)
        if(!visited[*i])
            utilTopologicalSort(*i,visited,Stack);
    
    Stack.push(v);
}
void Graph::topologicalSort()
{
    stack<int> Stack;
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    
    for(int i =0;i<V;i++)
        if(!visited[i])
            utilTopologicalSort(i,visited,Stack);
    
    while(!Stack.empty())
    {
        cout << Stack.top() <<" ";

        Stack.pop();
    }

}
int main()
{
    Graph g(6);
    g.addEdge(5, 2); 
	g.addEdge(5, 0); 
	g.addEdge(4, 0); 
	g.addEdge(4, 1); 
	g.addEdge(2, 3); 
	g.addEdge(3, 1);
    cout << "Following is a Topological Sort of the given graph \n"; 

    g.topologicalSort(); 

	return 0; 

    
}