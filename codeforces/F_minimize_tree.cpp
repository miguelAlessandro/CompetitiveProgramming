#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int N = 50004;
long long r;
vector<ii> graph[N];
int n;
long long mini_dis, mini_dis2;
int dis[N];
long long dmini[N];
int w[N];
int p[N];
bool vis[N], inPath[N];

int dfs(int x, int p){
	w[x] = 1;

	for(auto v : graph[x])
		if(v.first != p)
			w[x] += dfs(v.first, x);

	return w[x];
}


void bfs(int x){

	queue<int> Q; Q.push(x);
	dis[x] = 0;
	vis[x] = true;
	while(not Q.empty()){
		int q = Q.front(); Q.pop();
		for(auto v : graph[q])
			if(not vis[v.first]){
				vis[v.first] = true;
				p[v.first] = q;
				dis[v.first] = dis[q] + v.second;
				Q.push(v.first);
			}
	}
}


void bfs2(int x){
	queue<int> Q;
	Q.push(x);
	while(not Q.empty()){
		int q = Q.front(); Q.pop();
		for(auto v : graph[q])
			if(v.first != q and not inPath[v.first]){
				mini_dis2 = min(mini_dis2, (long long)dis[v.first]);			
				Q.push(v.first);
			}
	}
}


void dfs2(int x, int p, long long mini){
	dmini[x] = min(mini, (long long)dis[x]);
	for(auto v : graph[x])
		if(v.first != p and inPath[v.first])
			dfs2(v.first, x, dmini[x]);
}

int main(){

	scanf("%d", &n);
	for(int x, y, z, i = 1; i < n; ++i){
		scanf("%d %d %d", &x, &y, &z);
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}
	
	dfs(1, -1);
	bfs(1);

	long long r = 0, rs;
	mini_dis = LLONG_MAX, mini_dis2 = LLONG_MAX;;
	int in;
	for(int i = 1; i <= n; ++i){
		r += dis[i];
		if(mini_dis > dis[i])
			mini_dis = dis[i],
			in = i;
	}

	
	while(in != 1){
		inPath[in] = true;
		in = p[in];
	}
	bfs2(1);
	dfs2(1, -1, 0);

	rs = r;

	for(int i = 2; i <= n; ++i)
		if(not inPath[i])
			r = min(r, rs + (mini_dis - dis[p[i]])*w[i]);
		else
			r = min(r, rs + (min(mini_dis2, dmini[i]) - dis[p[i]])*w[i]);
		

	printf("%lld\n", r);

	return 0;
}
