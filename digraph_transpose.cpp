#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace::std;

typedef pair<int, int> ii;

const int N = 100005;
int n, m;


vector< pair<bool, ii> > adj[N];
vetor<int> ord;
bool vis[N];
int dis[N];

void dfs_complete(const int n){

    for(int i = 1; i <= n; ++i) vis[i] = false;
    for(int i = 1; i <= n; ++i) if(not vis[i])
        dfs(i);
    reverse(ord.begin(), ord.end());
}

void dfs(const int x){
    vis[x] = true;
    for(auto u : adj[x])
        if(u.first and not vis[u.second.first])
            dfs(u.second.first);

    ord.push_back(x);
}

void minimum_path(const int x, const int n){
    for(int i = 1; i <= n; ++i) dis[i] = (1<<24);
    for(auto v : ord)
        for(auto u : adj[v]) if(not u.first)
                dis[v] = min(dis[v], dis[u.second.first] + u.second.second);
}       


int main(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(true, ii(b, w)));
        adj[b].push_back(make_pair(false, ii(a, w)));
    }
        

    return 0;
}
