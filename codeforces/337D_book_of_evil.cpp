#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, m, d, ans;
int P[N], dp[N];
bool vis[N], R[N];
vector<int> graph[N];
vector< pair<int, int> > dis[N];

int dfs(int x){
	
	vis[x] = true;
	R[x] ? dp[x] = 0 : dp[x] = INT_MIN;

	for(int v : graph[x])
		if(not vis[v]){
			int r = dfs(v);
			if(r >= 0) dp[x] = max(dp[x], r + 1);
		}

	return dp[x];
}

void dfs2(int x){

	vis[x] = true;

	for(int v : graph[x])
		if(not vis[v]) 
			if(dp[v] >= 0) dis[x].push_back({dp[v] + 1, v});
			else dis[x].push_back({INT_MIN, v});

	sort(dis[x].begin(), dis[x].end(), greater< pair<int, int> >());

	//cout << x << " "  << dis[x].size() << endl;

	int r = dis[x][0].first;
	if(r == INT_MIN)
		if(R[x]) r = 0;
		else r = d + 1;	

	ans += dis[x][0].first <= d;

	if(dis[x][0].first == INT_MIN){
		for(auto v : graph[x])
			if(not vis[v]){
				if(R[x]) dis[v].push_back({1, x});
				dfs2(v);
			}
	}
	else if(dis[x].size() == 1){
		if(R[x]) dis[graph[x].front()].push_back({1, x});
		if(not vis[graph[x].front()]) dfs2(graph[x].front());
	}
	else{
		int Idf = dis[x].front().second;
		for(auto v : graph[x])
			if(not vis[v])
				if(v == Idf){
					int r = dis[x][1].first;
					if(r != INT_MIN) r += 1;
					else if(R[x]) r = 1;
						
					dis[v].push_back({r, x});
					dfs2(v);
				}
				else{
					dis[v].push_back({dis[x][0].first + 1, x});
					dfs2(v);
				}
	}
}


int main(){

	scanf("%d %d %d", &n, &m, &d);	
	
	for(int i = 0; i < m; ++i){
		scanf("%d", P+i);
		R[P[i]] = true;
	}

	if(n == 1){
		puts("1");
		return 0;
	}

	for(int x, y, j = 1; j < n; ++j){
		scanf("%d %d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(1);
	memset(vis, false, sizeof vis);
	dfs2(1);
	
	printf("%d\n", ans);

	return 0;
}
