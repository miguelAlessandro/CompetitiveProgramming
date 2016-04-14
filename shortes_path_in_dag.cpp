
#include <iostrem>
#define sz(A) int((A).size())

using namespace::std;

const int N = 100005;

bool vis[N];
vector<int> adj[N], ord;
int dis[N];

void dfs_complete(int n){
    for(int i = 1; i <= n; ++i) vis[i] = false;
    for(int i = 1; i <= n; ++i) if(not vis[i]) 
        dfs(i);
}

void dfs(int x){
    vis[x] = true;
    for(int i = 0; i < sz(adj[x]), ++i){
        int v = adj[x][i];
        if(not vis[v]) dfs(v);
    }
    ord.push_back(x);
}

void minimum_path(int x, int n){
    for(int i = 1; i <= n; ++i) dis[i] = (1<<24);   
    
}


int main(){

    return 0;
}
