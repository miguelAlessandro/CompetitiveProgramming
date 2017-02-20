#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector< pair<int, long long> > a[N];
long long w[N];
bool vis[N];
int n, T;

void dfs(int x, long long mini, long long len){
	vis[x] = true; T++;
	for(auto v : a[x])
		if(not vis[v.first] and len+v.second - mini <= w[v.first])
			dfs(v.first, min(mini, len+v.second), len+v.second);		
}

int main(){

	scanf("%d", &n);
	for(int x, i = 1; i <= n; ++i){
		scanf("%d", &x);
		w[i] = x;
	}

	int x, y;
	for(int i = 2; i <= n; ++i){
		scanf("%d %d", &x, &y);
		a[i].push_back(make_pair(x, y));
		a[x].push_back(make_pair(i, y));
	}

	dfs(1, 0, 0);

	printf("%d\n", n-T);

	return 0;
}
