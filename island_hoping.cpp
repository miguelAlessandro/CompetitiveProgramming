#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int N = 55;
int n, m, t, s, d, w;
string x, y;
map<string, int> Id;
vector<int> adj[N];
int graph[N][N];
int F[N];
int dp[N][1000000];

bool backtracking(int pos, int gas){
	if(pos == n-1) return true;
	if(dp[pos][gas] != -1) return dp[pos][gas];	

	gas += F[pos];
	int ans = false;
	for(int v : adj[pos])
		if(gas >= graph[pos][v])
			ans |= backtracking(v, gas-graph[pos][v]);

	return dp[pos][gas-F[pos]] = ans;
}




int main(){

	cin >> t;
	while(t--){

		memset(graph, 0, sizeof graph);
		for(int i = 0; i < 55; ++i) adj[i].clear();

		cin >> n;		
		for(int i = 0; i < n; ++i){
			cin >> x >> w;
			Id[x] = i;
			if(x == "start") s = i;
			if(x == "end") d = i;
			F[Id[x]] = w;
		}
		cin >> m;	
		for(int ix, iy, i = 0; i < m; ++i){
			cin >> x >> y >> w;
			ix = Id[x];
			iy = Id[y];
			adj[ix].push_back(iy);
			adj[iy].push_back(ix);
			graph[ix][iy] = graph[iy][ix] = w;
		}
		memset(dp, -1, sizeof dp);		
		int lo = 0, hi = 100; 
		while(lo < hi){
			int mid = lo + (hi-lo)/2;
			if(not backtracking(0, mid)) lo = mid+1;
			else hi = mid;
		}
		if(not backtracking(0, lo)) cout << lo << endl; 
		else cout << "Imposible" << endl;
	}

	return 0;
}
