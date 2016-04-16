#include <iostream>
#include <vector>
#include <cstdio>

using namespace::std;

//con lista de adjacencia
const int maxV = 100000;
const int maxE = 100000;

vector<int> adj[maxV];
bool vis[maxV];
int n, m;

int dfs(const int x){
    vis[x] = true;
    for(int i = 0; i < int(adj[i].size()); ++i)
        if(not vis[adj[x][i]])
            dfs(adj[x][i]);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    return 0;
}


//con matriz de adjacencia
const int maxV = 1000;
const int maxE = maxV*maxV;

bool adj[maxV][maxV];
bool vis[maxV];

int dfs(const int x, const int n){ //n es el número de vertices
    vis[x] = true;
    for(int i = 0; i < n; ++i)
        if(adj[x][i] and not vis[i])
            dfs(i, n);
}

int n, m;

int main(){
        
    cin >> n >> m;       
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        --a; --b; //para utilizar los vertices desde 0 a n-1
        adj[a][b] = adj[b][a] = true;
    }

    dfs(0);
    
    return 0;
}










