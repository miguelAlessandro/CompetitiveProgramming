#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 100000 + 5;

bool vis[N];
vector<int> adj[N];
int n, m;

bool isTree(int x, int P){
    vis[x] = true;
    for(auto u : adj[x])
        if(u == P) continue;
        else if(vis[u] or not isTree(u, x)) return false;
    return true;
}

int main(){

    scanf("%d %d", &n, &m);
    for(int a, b, i = 0; i < m; ++i){
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool is_forest = true;
    int T = 0;
    for(int i = 1; i <= n; ++i)
        if(not vis[i]){
            if(isTree(i, 0))
                T = T + 1;
            else{
                is_forest = false;
                break;
            }
        }

    if(is_forest) puts(T == 1 ? "Tree" : "Forest");
    else puts("Simple Graph");

    return 0;
}
