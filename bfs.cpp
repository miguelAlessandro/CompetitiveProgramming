#include <iostream>
#include <queue>
#include <vector>

using namespace::std;

//para lista de adjacencia
const int maxV = 100000;
const int maxE = 100000;

vector<int> adj[maxV];
bool vis[maxV];

void bfs(const int x){
    
    queue<int> Q; 
    Q.push(x);
    while(not Q.empty()){
        int q = Q.front(); Q.pop();
        vis[q] = true;
        for(int i = 0; i < int(adj[q].size()); ++i)
            if(not vis[adj[q][i]])
                Q.push(adj[q][i]);
    }
}

int n, m;

int main(){

    
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        --a; --b; //para usar los nodos de 0 a n-1
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(0);

    return 0;
}

//para matriz de adjacencia
const int maxV = 1000;
const int maxE = maxV*maxV;

int adj[maxV][maxV];
bool vis[maxV];

void bfs(const int x, const int n){
    
    queue<int> Q; Q.push(x);
    vis[x] = true;
    while(not Q.empty()){
        int q = Q.front(); Q.pop();
        vis[q] = true;
        for(int i = 0; i < n; ++i)
            if(adj[q][i] and not vis[i])
                Q.push(i);
    }
}

int n, m;

int main(){
    
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        --a; --b; //para usar los nodos de 0 a n-1
        adj[a][b] = adj[b][a] = true;
    }

    bfs(0);

    return 0;
}
