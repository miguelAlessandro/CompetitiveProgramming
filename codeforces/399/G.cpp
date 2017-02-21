#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 100005;
int n, root;
int m1[N], m2[N], ans[N];

vector<int> adj[N];
vector<pii> A[N], B[N];

void dfs(int x, int p = 0){

	m1[x] = 1;
	m2[x] = 0;
	
	for(int v : adj[x])
		if(v != p){
			dfs(v, x);
			m1[x] += m1[v];
			m2[x] = max(m2[x], m1[v]);
			A[x].push_back({m1[v], v});
			B[x].push_back({m2[v], v});
		}

	sort(A[x].begin(), A[x].end(), greater<pii>());
	sort(B[x].begin(), B[x].end(), greater<pii>());
}

void dfs2(int x, int p = 0, int a = 0, int b = 0){
	
	if(p){
		A[x].push_back({a, root});
		B[x].push_back({b, root});
		
		sort(A[x].begin(), A[x].end(), greater<int>);		
		sort(B[x].begin(), B[x].end(), greater<int>);
	}
		
	

	if(A[x].size() == 1)		
		ans[x] = A[x][0].first;
	else{
		if(A[x][0].second == B[x][0].second) ans[x] = min(A[x][0].first + max(B[x][1].first - 1, 0), A[x][1].first + max(B[x][0].first - 1, 0));
		else ans[x] = A[x][0].first + max(B[x][0].first - 1, 0);
	}
	

	for(int v : adj[x])
		if(v != p){
			if(adj[x].size() == 1)
				dfs2(v, x, 1, 0);
			else{
				if(A[x][0].second == v) dfs2(v, x, A[x][1].first, m1[root] - m1[v]);
				else dfs2(v, x, A[x][0].first ,m1[root] - m1[v]);
			}
		}
}


int main(){

	scanf("%d", &n);	
	for(int x, y, i = 0; i < n; ++i){
		scanf("%d %d", &x, &y);

		if(x == 0) root = y;
		else{
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
	}

	dfs(root);
	dfs2(root);

	for(int i = 1; i <= n; ++i)
		printf("%d\n", ans[i]);

	return 0;
}
