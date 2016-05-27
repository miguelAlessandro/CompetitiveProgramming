#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int N = 100000;
typedef pair<int, int> ii;
vector<ii> adj[N];
bool vis[N];
priority_queue< ii, vector<ii>, greater<ii> > pq;
int n, m;

int MST_Prim(int x){
    for(int i = 0; i < n; ++i) vis[i] = false;
    
    int mst_cost = 0;
    pq.push(push(0, x));
    while(not pq.empty()){
        ii u = pq.top(); pq.pop();
	if(not vis[u.second]){
            vis[u.second] = true;
            mst_cost += u.first;
            for(auto v : adj[u.second])
                if(not vis[v.first])
                    pq.push(ii(v.second, v.first));
        }
    }
    return ms_cost;
}


int main(){

    return 0;
}
