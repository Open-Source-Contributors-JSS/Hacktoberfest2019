#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define visited 1

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi visit;
vi predecessor;
vector<vii> AdjList(100);
vector<int> topology;

void dfs(int v){
    visit[v] = visited;
    for (int i = 0; i < (int)AdjList[v].size(); i++){
        if (visit[AdjList[v][i].first] != visited){
            predecessor[AdjList[v][i].first] = v;
            dfs(AdjList[v][i].first);
        }
    }
    topology.pb(v);
}

int main(){
    int v1, v2;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        visit.pb(-1);
        predecessor.pb(-2);
    }
    while (scanf("%d %d", &v1, &v2) != EOF){
        if (v1 != 0 && v2 != 0){
            AdjList[v1].pb(make_pair(v2, 0));
        }
    }
    //generating the topoly of this graph using DFS
    for (int i = 1; i < n; i++){
        if (visit[i] != visited)
            dfs(i);
    }
    for (int i = topology.size() - 1; i >= 0; i--){
        printf("%d ", topology[i]);
    }
    printf("\n");
    return 0;
}