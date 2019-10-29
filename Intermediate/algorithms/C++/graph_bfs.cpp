#include <bits/stdc++.h>
using namespace std;
int vis[10];
vector<int> adj[10];
void bfs(int a) {
	queue<int> q;
	q.push(a);
	vis[a]=1;
	cout<<a<<"->";
	while(!q.empty()) {
		int r=q.front();
		q.pop();
		for(int i=0;i<adj[r].size();i++) {
			if(adj[r][i]==0) {
				q.push(adj[i]);
				cout<<adj[r][i]<<"->";
				vis[adj[r][i]]=1;
			}
		}
	}
}
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bfs(1);
}
			
			
